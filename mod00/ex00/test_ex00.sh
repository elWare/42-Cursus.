#!/bin/bash

# --- Configuración del Tester ---
EXEC_PATH="./megaphone" # Ruta a tu ejecutable megaphone
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Función para ejecutar una prueba
# Uso: run_test "Nombre de la prueba" "SALIDA_ESPERADA" [ARG1] [ARG2] ...
run_test() {
    TEST_CASE_NAME=$1
    EXPECTED_OUTPUT=$2
    COMMAND_ARGS="${@:3}" # El resto de los argumentos son los que se pasan a megaphone

    echo -e "\n${YELLOW}--- Ejecutando Prueba: $TEST_CASE_NAME ---${NC}"
    echo -e "Comando: ${EXEC_PATH} ${COMMAND_ARGS}"
    
    # Ejecuta el comando y captura la salida estándar
    ACTUAL_OUTPUT=$(${EXEC_PATH} ${COMMAND_ARGS})
    
    echo "Salida esperada: \"$EXPECTED_OUTPUT\""
    echo "Salida real:     \"$ACTUAL_OUTPUT\""

    if [ "$ACTUAL_OUTPUT" = "$EXPECTED_OUTPUT" ]; then
        echo -e "${GREEN}  [OK] Prueba '${TEST_CASE_NAME}' pasada.${NC}"
        return 0
    else
        echo -e "${RED}  [ERROR] Prueba '${TEST_CASE_NAME}' fallida.${NC}"
        return 1
    fi
}

# --- Preparación: Limpiar y compilar ---
echo -e "${GREEN}--- Limpiando y Compilando megaphone ---${NC}"
make re # Ejecuta 'make re' para asegurar una compilación limpia
if [ $? -ne 0 ]; then
    echo -e "${RED}Error de compilación para megaphone. Abortando pruebas.${NC}"
    exit 1
fi
echo -e "${GREEN}Compilación exitosa.${NC}"

# Verificar si el ejecutable existe
if [ ! -f "${EXEC_PATH}" ]; then
    echo -e "${RED}El ejecutable megaphone no se encontró. Asegúrate de que tu Makefile lo cree en el directorio actual.${NC}"
    exit 1
fi

# --- PRUEBAS ESPECÍFICAS ---

# Prueba 1: Sin argumentos [2]
run_test "Sin Argumentos" "* LOUD AND UNBEARABLE FEEDBACK NOISE *" ""

# Prueba 2: Un argumento simple
run_test "Un Argumento Simple" "HOLA MUNDO" "hola mundo"

# Prueba 3: Múltiples argumentos [2]
run_test "Múltiples Argumentos" "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." "Damnit" " ! " "Sorry students, I thought this thing was off."

# Prueba 4: Argumentos con mayúsculas y minúsculas y números
run_test "Argumentos Mixtos" "HELLO 42 SCHOOL" "Hello" "42 School"

# Prueba 5: Argumentos con caracteres especiales
run_test "Argumentos con Especiales" "WHAT?! THIS IS FUN_123" "what?!" "this is fun_123"

# Prueba 6: Argumentos completamente en blanco (vacíos) - el shell los eliminaría, mejor pasar como string vacía
# Aquí se usa una string vacía literal "" para simular un argv[i] vacío si el shell lo permite
run_test "Argumentos Vacios" "* LOUD AND UNBEARABLE FEEDBACK NOISE *" "" 

# Prueba 7: Un argumento con espacios internos
run_test "Argumento con Espacios Internos" "ESTO ES UN MENSAJE LARGO" "esto es un mensaje largo"

# Prueba 8: Mensaje largo (del ejemplo original) [1]
run_test "Mensaje Largo Original" "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." "shhhhh... I think the students are asleep..."

# --- Limpieza final ---
echo -e "\n${GREEN}--- Limpiando archivos objeto y ejecutable de megaphone ---${NC}"
make fclean

echo -e "\n${GREEN}--- Fin de las pruebas de megaphone ---${NC}"
