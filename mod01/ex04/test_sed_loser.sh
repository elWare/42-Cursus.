#!/bin/bash

# --- Configuración del Tester ---
EXEC_NAME="sed_for_losers" # Nombre de tu ejecutable (ajusta si es diferente)
SOURCE_FILE="main.cpp"     # Archivo fuente de tu programa
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m'               # No Color

# --- Variables de archivos temporales ---
TEST_INPUT="test_input.txt"
EXPECTED_OUTPUT_FILE="test_input.txt_replaced"
ACTUAL_OUTPUT_FILE="actual_output.txt"
TEMP_MAIN_CPP="temp_main.cpp" # Para evitar conflictos con tu main.cpp real si está en el mismo nivel

# --- Funciones Auxiliares ---

# compilar_programa: Compila el programa usando el Makefile
compilar_programa() {
    echo -e "${BLUE}--- Compilando ${EXEC_NAME} ---${NC}"
    make re
    if [ $? -ne 0 ]; then
        echo -e "${RED}Error de compilación para ${EXEC_NAME}. Abortando pruebas.${NC}"
        exit 1
    fi
    echo -e "${GREEN}Compilación exitosa.${NC}"
    # Verificar si el ejecutable existe
    if [ ! -f "./${EXEC_NAME}" ]; then
        echo -e "${RED}El ejecutable ${EXEC_NAME} no se encontró. Asegúrate de que tu Makefile lo cree en el directorio actual.${NC}"
        exit 1
    fi
}

# cleanup: Limpia los archivos temporales y el ejecutable del proyecto
cleanup() {
    echo -e "\n${BLUE}--- Limpiando archivos temporales y de proyecto ---${NC}"
    rm -f ${TEST_INPUT} ${TEST_INPUT}_replaced ${EXPECTED_OUTPUT_FILE} ${ACTUAL_OUTPUT_FILE} ${TEMP_MAIN_CPP}
    make fclean
}

# run_test: Ejecuta una prueba de reemplazo y compara
# Uso: run_test "Nombre_Prueba" "Contenido_Input" "Cadena_Buscar" "Cadena_Reemplazar" "Contenido_Esperado_Output"
run_test() {
    TEST_NAME=$1
    INPUT_CONTENT=$2
    SEARCH_STR=$3
    REPLACE_STR=$4
    EXPECTED_REPLACED_CONTENT=$5

    echo -e "\n${YELLOW}--- Ejecutando Prueba: ${TEST_NAME} ---${NC}"

    # 1. Crear archivo de entrada
    echo "${INPUT_CONTENT}" > "${TEST_INPUT}"
    echo -e "  ${BLUE}Archivo de entrada ('${TEST_INPUT}'):${NC}"
    echo "${INPUT_CONTENT}"

    # 2. Capturar la salida esperada para el archivo .replaced
    echo "${EXPECTED_REPLACED_CONTENT}" > "${EXPECTED_OUTPUT_FILE}"
    echo -e "  ${BLUE}Contenido esperado en '${TEST_INPUT}_replaced':${NC}"
    echo "${EXPECTED_REPLACED_CONTENT}"

    # 3. Ejecutar el programa
    PROGRAM_CMD="./${EXEC_NAME} ${TEST_INPUT} \"${SEARCH_STR}\" \"${REPLACE_STR}\""
    echo -e "  ${BLUE}Comando: ${PROGRAM_CMD}${NC}"
    PROGRAM_STDOUT=$(${PROGRAM_CMD}) # Captura la salida estándar (mensaje de éxito)
    PROGRAM_EXIT_CODE=$?             # Captura el código de salida

    # 4. Verificar el código de salida del programa
    if [ "${PROGRAM_EXIT_CODE}" -ne 0 ]; then
        echo -e "${RED}  [ERROR] Programa terminó con código de error ${PROGRAM_EXIT_CODE}. Se esperaba 0.${NC}"
        echo "${PROGRAM_STDOUT}" # Muestra la salida del programa por si es un error
        return 1
    fi

    # 5. Comparar el archivo de salida generado
    if [ ! -f "${TEST_INPUT}_replaced" ]; then
        echo -e "${RED}  [ERROR] El archivo de salida '${TEST_INPUT}_replaced' NO fue creado.${NC}"
        return 1
    fi

    diff_output=$(diff -u "${EXPECTED_OUTPUT_FILE}" "${TEST_INPUT}_replaced")
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}  [OK] La salida de reemplazo del archivo coincide.${NC}"
        return 0
    else
        echo -e "${RED}  [ERROR] La salida de reemplazo del archivo NO coincide.${NC}"
        echo "$diff_output"
        return 1
    fi
}

# run_error_test: Ejecuta una prueba para verificar manejo de errores
# Uso: run_error_test "Nombre_Prueba" "Código_Salida_Esperado" "Mensaje_Error_Esperado" "Comando_a_Ejecutar"
run_error_test() {
    TEST_NAME=$1
    EXPECTED_EXIT_CODE=$2
    EXPECTED_ERR_MSG=$3
    COMMAND=$4

    echo -e "\n${YELLOW}--- Ejecutando Prueba de Error: ${TEST_NAME} ---${NC}"
    echo -e "  ${BLUE}Comando: ${COMMAND}${NC}"

    # Ejecutar el comando y capturar salida de error (stderr) y código de salida
    ACTUAL_ERR_MSG=$(eval "${COMMAND}" 2>&1 >/dev/null) # Redirige stdout a /dev/null, stderr a ACTUAL_ERR_MSG
    ACTUAL_EXIT_CODE=$?

    echo "  Código de salida esperado: ${EXPECTED_EXIT_CODE}, real: ${ACTUAL_EXIT_CODE}"
    echo "  Mensaje de error esperado: '${EXPECTED_ERR_MSG}'"
    echo "  Mensaje de error real:     '${ACTUAL_ERR_MSG}'"

    PASS=0
    if [ "${ACTUAL_EXIT_CODE}" -eq "${EXPECTED_EXIT_CODE}" ]; then
        echo -e "${GREEN}  [OK] Código de salida correcto.${NC}"
        PASS=$((PASS + 1))
    else
        echo -e "${RED}  [ERROR] Código de salida incorrecto.${NC}"
    fi

    if [[ "${ACTUAL_ERR_MSG}" == *"${EXPECTED_ERR_MSG}"* ]]; then # Busca el mensaje esperado como subcadena
        echo -e "${GREEN}  [OK] Mensaje de error correcto.${NC}"
        PASS=$((PASS + 1))
    else
        echo -e "${RED}  [ERROR] Mensaje de error incorrecto.${NC}"
    fi

    if [ "${PASS}" -eq 2 ]; then
        echo -e "${GREEN}  [OK] Prueba '${TEST_NAME}' pasada.${NC}"
        return 0
    else
        echo -e "${RED}  [ERROR] Prueba '${TEST_NAME}' fallida.${NC}"
        return 1
    fi
}

# --- Bloque principal del script ---
trap cleanup EXIT # Asegura que la limpieza se haga incluso si el script falla

# 0. Crear un main.cpp temporal para el ejecutable (si el tuyo se llama main.cpp)
#    Esto es para que el Makefile sepa compilarlo como un único archivo.
#    Si tu ejecutable se llama main (por make sin especificar NAME), o el .cpp ya tiene un nombre específico,
#    quizás no necesites este paso o debas ajustarlo.
cp "${SOURCE_FILE}" "${TEMP_MAIN_CPP}"
# Ajustar el Makefile para usar TEMP_MAIN_CPP si es necesario, o asegurar que NAME esté bien definido.

compilar_programa # Compilar el programa antes de las pruebas

# -------------------------------------------------------------------------- #
# --- BATERÍA DE PRUEBAS ---
# -------------------------------------------------------------------------- #

# PRUEBAS DE ERRORES EN LA ENTRADA
run_error_test "Faltan argumentos (0)" 1 "Número de argumento incorrecto" "./${EXEC_NAME}"
run_error_test "Faltan argumentos (1)" 1 "Número de argumento incorrecto" "./${EXEC_NAME} input.txt"
run_error_test "Faltan argumentos (2)" 1 "Número de argumento incorrecto" "./${EXEC_NAME} input.txt buscar"
run_error_test "Argumento extra" 1 "Número de argumento incorrecto" "./${EXEC_NAME} input.txt buscar reemplazar extra_arg" # Tu código verifica !=4

run_error_test "Cadena a buscar vacía" 1 "La cadena a buscar no puede estar vacia" "./${EXEC_NAME} ${TEST_INPUT} \"\" reemplazar"

run_error_test "Archivo de entrada no existente" 1 "No se puede abrir el archivo de entrada" "./${EXEC_NAME} no_existe.txt buscar reemplazar"

# PRUEBAS DE FUNCIONALIDAD DE REEMPLAZO
run_test "Reemplazo simple" \
"Este es un texto de prueba. Hola mundo, hola a todos." \
"hola" "ADIOS" \
"Este es un texto de prueba. ADIOS mundo, ADIOS a todos."

run_test "Reemplazo de múltiples ocurrencias en una línea" \
"AAAAABBBBAAAAACCCCAAAA" \
"AAAA" "XXXX" \
"XXXXBBBBXXXXCCCCXXXX"

run_test "Reemplazo sin ocurrencias" \
"No hay nada que reemplazar aqui." \
"buscar" "reemplazar" \
"No hay nada que reemplazar aqui."

run_test "Reemplazo de cadena vacía (en archivo)" \
"Esto es una linea.Otra linea." \
"" "VACIO" \
"Error: La cadena a buscar no puede estar vacia." # Este caso debería ser atrapado por tu validación de entrada

run_test "Reemplazo de una letra" \
"banana" \
"a" "X" \
"bXnXnX"

run_test "Reemplazo de parte de una palabra" \
"paralelepipedo" \
"le" "LI" \
"paraLIpípedo"

run_test "Reemplazo con cadena de reemplazo más larga" \
"abc" \
"b" "XXXX" \
"aXXXXc"

run_test "Reemplazo con cadena de reemplazo más corta" \
"abcdef" \
"cde" "X" \
"abXf"

run_test "Reemplazo con búsqueda que forma parte de la reemplazado (no debería haber bucle infinito)" \
"ababa" \
"a" "ax" \
"axbaxbax" # Si buscas 'a' y reemplazas con 'ax', la 'a' de 'ax' no se debe buscar de nuevo en la misma iteración

run_test "Archivo con varias líneas y reemplazos" \
"Linea uno, hola mundo.
Linea dos, hola de nuevo.
Linea tres. Hola.
Fin del archivo." \
"hola" "SALUDO" \
"Linea uno, SALUDO mundo.
Linea dos, SALUDO de nuevo.
Linea tres. SALUDO.
Fin del archivo."

run_test "Reemplazo con 'null' o strings que simulan nulos" \
"NullPointer, null, NULL_VAL" \
"null" "ZERO" \
"NullPointer, ZERO, NULL_VAL"