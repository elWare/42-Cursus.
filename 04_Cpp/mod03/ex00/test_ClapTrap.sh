#!/bin/bash

# --- Configuración del Tester ---
EXEC_NAME="claptrap" # Nombre de tu ejecutable ClapTrap
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m'     # No Color

# --- Log de Referencia (Basado en tus archivos .cpp y .hpp) ---
# Este es el log que tu programa debería generar, incluyendo todos los mensajes de cout.
# ¡Asegúrate de que tus couts en ClapTrap.cpp y main.cpp coincidan EXACTAMENTE con esto!
read -r -d '' EXPECTED_OUTPUT_COMPLETE <<EOF
ClapTrap constructo con parametros llamado y creado: Bobby
 
* * * * * Bobby is ready to perform! * * * * *

Hit Points    : 10
Energy Points : 10
Attack Damage : 2

Status        : OK

* * * * * *  Bobby's show begins   * * * * * *

ClapTrap Bobby ataca a Peter Pan causando 2 puntos de daños!
ClapTrap Bobby ataca a Bambi causando 2 puntos de daños!

ClapTrap Bobby recibe 4 puntos de daños!
ClapTrap Bobby recibe 4 puntos de daños!
ClapTrap Bobby es reparado en 10 puntos!

ClapTrap Bobby ataca a Pinocho causando 2 puntos de daños!
ClapTrap Bobby ataca a Mulan causando 2 puntos de daños!
ClapTrap Bobby ataca a Tarzan causando 2 puntos de daños!
ClapTrap Bobby intenta atacar a Nemo pero, no tiene energía suficiente.

* * * * * * * Bobby's show ends  * * * * * * *

ClapTrap destructor llamado y destruido Bobby
EOF

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

# cleanup: Limpia los archivos del proyecto
cleanup() {
    echo -e "\n${BLUE}--- Limpiando archivos de proyecto ---${NC}"
    make fclean
}

# run_test_case: Ejecuta el programa y compara su salida con la esperada
run_test_case() {
    TEST_NAME=$1
    EXPECTED_STDOUT_PATTERN=$2 

    echo -e "\n${YELLOW}--- Ejecutando Prueba: ${TEST_NAME} ---${NC}"
    COMMAND="./${EXEC_NAME}"
    echo -e "  ${BLUE}Comando: ${COMMAND}${NC}"

    ACTUAL_STDOUT=$(eval "${COMMAND}")
    ACTUAL_EXIT_CODE=$?

    # Imprimir salidas para depuración
    echo "  Salida REAL (completa):"
    echo -e "${ACTUAL_STDOUT}"
    echo "  ----------------------------------------"
    echo "  Salida ESPERADA (completa):"
    echo -e "${EXPECTED_STDOUT_PATTERN}"
    echo "  ----------------------------------------"
    echo "  Código de salida esperado: 0, real: ${ACTUAL_EXIT_CODE}"

    PASSED=true
    # Normalizar ambas salidas para la comparación (quitar espacios extra, saltos de línea)
    PROCESSED_EXPECTED=$(echo -e "${EXPECTED_STDOUT_PATTERN}" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//' | tr -d '\n')
    PROCESSED_ACTUAL=$(echo -e "${ACTUAL_STDOUT}" | sed 's/^[[:space:]]*//;s/[[:space:]]*$//' | tr -d '\n')

    if [ "${PROCESSED_ACTUAL}" != "${PROCESSED_EXPECTED}" ]; then
        echo -e "${RED}  [ERROR] La salida del programa NO coincide con el patrón esperado.${NC}"
        echo -e "\n--- Diferencia DETALLADA (diff -u) ---${NC}"
        diff -u <(echo -e "${EXPECTED_STDOUT_PATTERN}") <(echo -e "${ACTUAL_STDOUT}")
        PASSED=false
    fi

    if [ "${ACTUAL_EXIT_CODE}" -ne 0 ]; then
        echo -e "${RED}  [ERROR] El programa terminó con código de salida ${ACTUAL_EXIT_CODE}. Se esperaba 0.${NC}"
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

# 1. Compilar el programa antes de las pruebas
compilar_programa

# 2. BATERÍA DE PRUEBAS

# PRUEBA 1: Flujo completo del main (basado en tu main.cpp y logs)
run_test_case "Flujo de Bobby el ClapTrap" "${EXPECTED_OUTPUT_COMPLETE}"

# PRUEBA 2: Validación con Valgrind (sin leaks, sin errores)
echo -e "\n${GREEN}--- PRUEBA DE VALGRIND ---${NC}"
make valgrind > /dev/null 2>&1 # Suprime la salida normal para solo mostrar el resultado de Valgrind
if [ $? -eq 0 ]; then
    echo -e "${GREEN}  [OK] Valgrind no detectó fugas de memoria ni errores.${NC}"
else
    echo -e "${RED}  [ERROR] Valgrind detectó fugas de memoria o errores. Revisa la salida detallada de Valgrind.${NC}"
    make valgrind # Ejecutar de nuevo para ver la salida completa si falla
fi

# --- Resumen de resultados ---
echo -e "\n${BLUE}--- FIN DE PRUEBAS DE ${EXEC_NAME} ---${NC}"