#!/bin/bash

# --- Configuración del Tester ---
EXEC_NAME="unnecessary_violence" # Nombre de tu ejecutable
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m'                     # No Color

# --- Funciones Auxiliares ---

# strip_timestamps: Elimina los timestamps del inicio de la línea si tu programa los usa.
# (Este proyecto no debería usar timestamps, pero es una buena práctica para reusar scripts)
strip_timestamps() {
    sed -E 's/^\[[0-9]{8}_[0-9]{6}\]\s//'
}

# run_test: Ejecuta una prueba y compara la salida
# Uso: run_test "Nombre_Prueba" "Salida_Esperada" "Comando_a_Ejecutar"
run_test() {
    TEST_NAME=$1
    EXPECTED_OUTPUT=$2
    COMMAND=$3

    echo -e "\n${YELLOW}--- Ejecutando Prueba: ${TEST_NAME} ---${NC}"
    echo -e "Comando: ${COMMAND}"

    ACTUAL_OUTPUT=$(eval "${COMMAND}" | strip_timestamps) # Ejecuta el comando y procesa la salida

    echo "Salida esperada:"
    echo "${EXPECTED_OUTPUT}"
    echo "-------------------"
    echo "Salida real:"
    echo "${ACTUAL_OUTPUT}"
    echo "-------------------"

    if [ "$(echo "${ACTUAL_OUTPUT}" | tr -d '\n')" = "$(echo "${EXPECTED_OUTPUT}" | tr -d '\n')" ]; then
        echo -e "${GREEN}  [OK] Prueba '${TEST_NAME}' pasada.${NC}"
        return 0
    else
        echo -e "${RED}  [ERROR] Prueba '${TEST_NAME}' fallida.${NC}"
        diff -u <(echo "${EXPECTED_OUTPUT}" | strip_timestamps) <(echo "${ACTUAL_OUTPUT}" | strip_timestamps)
        return 1
    fi
}

# --- Preparación: Limpiar y compilar ---
echo -e "${GREEN}--- Limpiando y Compilando ${EXEC_NAME} ---${NC}"
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

# --- PRUEBAS ESPECÍFICAS ---

# PRUEBA 1: Flujo básico de HumanA y HumanB sin heap
EXPECTED_1=$(cat <<EOF
--- Inicio del Programa 'Unnecessary Violence' ---

--- Escenario 1: HumanA ---
Arma <crude spiked club> ha sido forjada.
HumanA <Bob> ha sido creado y empuñará el arma.
Bob ataca con su arma crude spiked club.
Weapon ha cambiado de tipo a <new shiny axe>.
Bob ataca con su arma new shiny axe.
HumanA <Bob> ha sido destruido.
Arma <new shiny axe> ha sido destruida.

--- Escenario 2: HumanB ---
Arma <heavy pistol> ha sido forjada.
HumanB <Jim> ha sido creado.
Jim intenta atacar pero no tiene arma.
HumanB <Jim> ahora empuñará el arma <heavy pistol>.
Jim ataca con su arma heavy pistol.
Weapon ha cambiado de tipo a <light machine gun>.
Jim ataca con su arma light machine gun.
Arma <sharp knife> ha sido forjada.
HumanB <Jim> ahora empuñará el arma <sharp knife>.
Jim ataca con su arma sharp knife.
Arma <sharp knife> ha sido destruida.
HumanB <Jim> ha sido destruido.
Arma <light machine gun> ha sido destruida.

--- Escenario 3: HumanB con arma en el HEAP ---
Arma <compound bow> ha sido forjada.
HumanB <Kevin> ha sido creado.
HumanB <Kevin> ahora empuñará el arma <compound bow>.
Kevin ataca con su arma compound bow.
Weapon ha cambiado de tipo a <laser cannon>.
Kevin ataca con su arma laser cannon.
Arma <laser cannon> ha sido destruida.
HumanB <Kevin> ha sido destruido.

--- Fin del Programa 'Unnecessary Violence' ---
EOF
)
run_test "Flujo Completo (main.cpp)" "${EXPECTED_1}" "./${EXEC_NAME}"

# PRUEBA 2: Validación con Valgrind (sin leaks, sin errores)
echo -e "\n${GREEN}--- PRUEBA DE VALGRIND ---${NC}"
make valgrind
if [ $? -eq 0 ]; then
    echo -e "${GREEN}  [OK] Valgrind no detectó fugas de memoria ni errores.${NC}"
else
    echo -e "${RED}  [ERROR] Valgrind detectó fugas de memoria o errores. Revisa la salida de Valgrind arriba.${NC}"
fi

# --- Limpieza al final ---
echo -e "\n${GREEN}--- Limpiando archivos de proyecto ---${NC}"
make fclean