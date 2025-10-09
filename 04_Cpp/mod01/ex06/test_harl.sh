#!/bin/bash

# --- Configuración del Tester ---
EXEC_NAME="harlFilter" # Nombre de tu ejecutable según el subject del ex06
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m'     # No Color

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

# run_test_case: Ejecuta una prueba y compara la salida
# Uso: run_test_case "Nombre_Prueba" "Nivel_Queja" "Salida_Esperada_stdout" "Salida_Esperada_stderr" "Codigo_Salida_Esperado"
run_test_case() {
    TEST_NAME=$1
    LEVEL_ARG=$2
    EXPECTED_STDOUT=$3
    EXPECTED_STDERR=$4
    EXPECTED_EXIT_CODE=$5

    echo -e "\n${YELLOW}--- Ejecutando Prueba: ${TEST_NAME} (${LEVEL_ARG}) ---${NC}"
    COMMAND="./${EXEC_NAME} ${LEVEL_ARG}"
    echo -e "  ${BLUE}Comando: ${COMMAND}${NC}"

    # Ejecutar el comando y capturar stdout, stderr y código de salida
    ACTUAL_STDOUT=$(eval "${COMMAND}")
    ACTUAL_EXIT_CODE=$?
    # Capturar stderr del comando.
    TEMP_STDERR_FILE=$(mktemp)
    eval "${COMMAND}" 2> "$TEMP_STDERR_FILE" >/dev/null
    ACTUAL_STDERR=$(cat "$TEMP_STDERR_FILE")
    rm "$TEMP_STDERR_FILE"


    echo "  Salida STDOUT esperada:"
    echo -e "${EXPECTED_STDOUT}" # Usamos -e para interpretar \n en la string esperada
    echo "  Salida STDOUT real:"
    echo -e "${ACTUAL_STDOUT}"   # Usamos -e para interpretar \n en la string real
    echo "  Salida STDERR esperada: '${EXPECTED_STDERR}'"
    echo "  Salida STDERR real:     '${ACTUAL_STDERR}'"
    echo "  Código de salida esperado: ${EXPECTED_EXIT_CODE}, real: ${ACTUAL_EXIT_CODE}"

    PASSED=true
    # Comparamos ignorando los espacios en blanco iniciales/finales y los saltos de línea para flexibilidad
    # También ignoramos los mensajes de "Constructor called" y "Destructor called" si están en el stdout
    FILTERED_ACTUAL_STDOUT=$(echo -e "${ACTUAL_STDOUT}" | grep -v '\[Harl\] Constructor called.' | grep -v '\[Harl\] Destructor called.' | sed 's/^[[:space:]]*//;s/[[:space:]]*$//' | tr -d '\n')
    FILTERED_EXPECTED_STDOUT=$(echo -e "${EXPECTED_STDOUT}" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//' | tr -d '\n')


    if [ "${FILTERED_ACTUAL_STDOUT}" != "${FILTERED_EXPECTED_STDOUT}" ]; then
        echo -e "${RED}  [ERROR] Salida STDOUT incorrecta (sin constructor/destructor).${NC}"
        # Para ver las diferencias más claramente, se usa diff directamente en las salidas filtradas
        diff -u <(echo -e "${EXPECTED_STDOUT}" | grep -v '\[Harl\] Constructor called.' | grep -v '\[Harl\] Destructor called.') <(echo -e "${ACTUAL_STDOUT}" | grep -v '\[Harl\] Constructor called.' | grep -v '\[Harl\] Destructor called.')
        PASSED=false
    fi

    if [ "$(echo -n "${ACTUAL_STDERR}")" != "$(echo -n "${EXPECTED_STDERR}")" ]; then
        echo -e "${RED}  [ERROR] Salida STDERR incorrecta.${NC}"
        diff -u <(echo -n "${EXPECTED_STDERR}") <(echo -n "${ACTUAL_STDERR}")
        PASSED=false
    fi

    if [ "${ACTUAL_EXIT_CODE}" -ne "${EXPECTED_EXIT_CODE}" ]; then
        echo -e "${RED}  [ERROR] Código de salida incorrecto.${NC}"
        PASSED=false
    fi

    if [ "$PASSED" = true ]; then
        echo -e "${GREEN}  [OK] Prueba '${TEST_NAME}' pasada.${NC}"
        return 0
    else
        echo -e "${RED}  [ERROR] Prueba '${TEST_NAME}' fallida.${NC}"
        return 1
    fi
}

# --- Bloque principal del script ---
trap cleanup EXIT # Asegura que la limpieza se haga incluso si el script falla

cleanup() {
    echo -e "\n${BLUE}--- Limpiando archivos del proyecto ---${NC}"
    make fclean
}

# 1. Compilar el programa antes de las pruebas
compilar_programa

# 2. BATERÍA DE PRUEBAS

# Variables para mensajes de error del main
# (Ajusta estas variables si tus mensajes en main.cpp son diferentes)
ARGC_ERR_MSG="Invalid arguments\nlevels: DEBUG, INFO, WARNING, ERROR"
USAGE_MSG="Usage: ./harlFilter <level>\nlevels: DEBUG, INFO, WARNING, ERROR"

# -------------------------------------------------------------------------- #
# PRUEBAS DE ARGUMENTOS (main.cpp)
# -------------------------------------------------------------------------- #
run_test_case "Sin argumentos" "" "" "${USAGE_MSG}" 1
run_test_case "Un argumento vacío" "\"\"" "" "${USAGE_MSG}" 1

# -------------------------------------------------------------------------- #
# PRUEBAS DE NIVELES DE QUEJA (Harl::complain)
# -------------------------------------------------------------------------- #
# Los mensajes deben coincidir exactamente con los de tu Harl.cpp
DEBUG_MSG="[ DEBUG ]\nMe encanta tener credito extra. ¡Me encanta!"
INFO_MSG="[ INFO ]\nNo puedo creer que agregar credito extra cueste tan poco dinero.\nHe estado viniendo aquí durante años y nunca tuve credito extra."
WARNING_MSG="[ WARNING ]\nCreo que debería tener credito extra. ¿Porque no los pedí?"
ERROR_MSG="[ ERROR ]\nEsto es inaceptable. ¡Quiero dinero extra AHORA MISMO!"
UNKNOWN_MSG="Invalid arguments\nlevels: DEBUG, INFO, WARNING, ERROR"

# Prueba DEBUG (debe mostrar DEBUG, INFO, WARNING, ERROR)
run_test_case "Nivel DEBUG" "DEBUG" \
"${DEBUG_MSG}\n${INFO_MSG}\n${WARNING_MSG}\n${ERROR_MSG}" \
"" 0

# Prueba INFO (debe mostrar INFO, WARNING, ERROR)
run_test_case "Nivel INFO" "INFO" \
"${INFO_MSG}\n${WARNING_MSG}\n${ERROR_MSG}" \
"" 0

# Prueba WARNING (debe mostrar WARNING, ERROR)
run_test_case "Nivel WARNING" "WARNING" \
"${WARNING_MSG}\n${ERROR_MSG}" \
"" 0

# Prueba ERROR (debe mostrar ERROR)
run_test_case "Nivel ERROR" "ERROR" \
"${ERROR_MSG}" \
"" 0

# -------------------------------------------------------------------------- #
# PRUEBAS DE NIVELES NO RECONOCIDOS
# -------------------------------------------------------------------------- #
run_test_case "Nivel Inválido (MINI)" "MINI" "${UNKNOWN_MSG}" "" 0
run_test_case "Nivel Inválido (UNKNOWN)" "UNKNOWN" "${UNKNOWN_MSG}" "" 0
run_test_case "Nivel con minúsculas" "debug" "${UNKNOWN_MSG}" "" 0

# --- Resumen de resultados ---
echo -e "\n${BLUE}--- FIN DE PRUEBAS DE HARL FILTER ---${NC}"