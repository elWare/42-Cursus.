#!/bin/bash

# --- Configuración del Tester ---
PROJECT_DIR="ex02"          # Directorio de tu proyecto ex02
EXEC_NAME="accounts"        # Nombre de tu ejecutable Account Class
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m'                # No Color

# Archivos temporales para logs procesados
TEMP_EXPECTED_LOG="expected_processed.log"
TEMP_ACTUAL_LOG="actual_processed.log"

# --- Log de Referencia (¡Copiado exactamente de tu entrada!) ---
# Este es el log que tu programa debería generar, ignorando solo el timestamp.
read -r -d '' EXPECTED_LOG <<EOF
[19920104_091532] index:0;amount:42;created
[19920104_091532] index:1;amount:54;created
[19920104_091532] index:2;amount:957;created
[19920104_091532] index:3;amount:432;created
[19920104_091532] index:4;amount:1234;created
[19920104_091532] index:5;amount:0;created
[19920104_091532] index:6;amount:754;created
[19920104_091532] index:7;amount:16576;created
[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
[19920104_091532] index:1;amount:54;deposits:0;withdrawals:0
[19920104_091532] index:2;amount:957;deposits:0;withdrawals:0
[19920104_091532] index:3;amount:432;deposits:0;withdrawals:0
[19920104_091532] index:4;amount:1234;deposits:0;withdrawals:0
[19920104_091532] index:5;amount:0;deposits:0;withdrawals:0
[19920104_091532] index:6;amount:754;deposits:0;withdrawals:0
[19920104_091532] index:7;amount:16576;deposits:0;withdrawals:0
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
[19920104_091532] index:1;p_amount:54;deposit:765;amount:819;nb_deposits:1
[19920104_091532] index:2;p_amount:957;deposit:564;amount:1521;nb_deposits:1
[19920104_091532] index:3;p_amount:432;deposit:2;amount:434;nb_deposits:1
[19920104_091532] index:4;p_amount:1234;deposit:87;amount:1321;nb_deposits:1
[19920104_091532] index:5;p_amount:0;deposit:23;amount:23;nb_deposits:1
[19920104_091532] index:6;p_amount:754;deposit:9;amount:763;nb_deposits:1
[19920104_091532] index:7;p_amount:16576;deposit:20;amount:16596;nb_deposits:1
[19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
[19920104_091532] index:1;amount:819;deposits:1;withdrawals:0
[19920104_091532] index:2;amount:1521;deposits:1;withdrawals:0
[19920104_091532] index:3;amount:434;deposits:1;withdrawals:0
[19920104_091532] index:4;amount:1321;deposits:1;withdrawals:0
[19920104_091532] index:5;amount:23;deposits:1;withdrawals:0
[19920104_091532] index:6;amount:763;deposits:1;withdrawals:0
[19920104_091532] index:7;amount:16596;deposits:1;withdrawals:0
[19920104_091532] index:0;p_amount:47;withdrawal:refused
[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
[19920104_091532] index:2;p_amount:1521;withdrawal:657;amount:864;nb_withdrawals:1
[19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1
[19920104_091532] index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
[19920104_091532] index:5;p_amount:23;withdrawal:refused
[19920104_091532] index:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1
[19920104_091532] index:7;p_amount:16596;withdrawal:7654;amount:8942;nb_withdrawals:1
[19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6
[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
[19920104_091532] index:1;amount:785;deposits:1;withdrawals:1
[19920104_091532] index:2;amount:864;deposits:1;withdrawals:1
[19920104_091532] index:3;amount:430;deposits:1;withdrawals:1
[19920104_091532] index:4;amount:1245;deposits:1;withdrawals:1
[19920104_091532] index:5;amount:23;deposits:1;withdrawals:0
[19920104_091532] index:6;amount:106;deposits:1;withdrawals:1
[19920104_091532] index:7;amount:8942;deposits:1;withdrawals:1
[19920104_091532] index:0;amount:47;closed
[19920104_091532] index:1;amount:785;closed
[19920104_091532] index:2;amount:864;closed
[19920104_091532] index:3;amount:430;closed
[19920104_091532] index:4;amount:1245;closed
[19920104_091532] index:5;amount:23;closed
[19920104_091532] index:6;amount:106;closed
[19920104_091532] index:7;amount:8942;closed
EOF

# --- Funciones Auxiliares ---

# strip_timestamp: Elimina el patrón de timestamp del inicio de una línea
# Ejemplo: "[19920104_091532] index:0;amount:42;created" -> "index:0;amount:42;created"
strip_timestamp() {
    echo "$1" | sed -E 's/^\[[0-9]{8}_[0-9]{6}\]\s//'
}

# --- Preparación: Limpiar y compilar ---
echo -e "${GREEN}--- Limpiando y Compilando ${EXEC_NAME} ---${NC}"
make re -C "${PROJECT_DIR}"
if [ $? -ne 0 ]; then
    echo -e "${RED}Error de compilación para ${EXEC_NAME}. Abortando pruebas.${NC}"
    exit 1
fi
echo -e "${GREEN}Compilación exitosa.${NC}"

# Verificar si el ejecutable existe
if [ ! -f "${PROJECT_DIR}/${EXEC_NAME}" ]; then
    echo -e "${RED}El ejecutable ${EXEC_NAME} no se encontró en ${PROJECT_DIR}/. Asegúrate de que tu Makefile lo cree allí.${NC}"
    exit 1
fi

# --- PRUEBA PRINCIPAL: Comparación de Logs ---
echo -e "\n${GREEN}--- PRUEBA PRINCIPAL: Comparación de la salida ---${NC}"

# 1. Ejecutar el programa y capturar la salida
echo "Ejecutando: ./${PROJECT_DIR}/${EXEC_NAME}"
ACTUAL_RAW_LOG=$(./"${PROJECT_DIR}"/"${EXEC_NAME}")

# 2. Procesar el log esperado (eliminar timestamps)
echo "$EXPECTED_LOG" | while IFS= read -r line; do
    strip_timestamp "$line" >> "$TEMP_EXPECTED_LOG"
done

# 3. Procesar el log real (eliminar timestamps)
echo "$ACTUAL_RAW_LOG" | while IFS= read -r line; do
    strip_timestamp "$line" >> "$TEMP_ACTUAL_LOG"
done

# 4. Comparar los logs procesados usando 'diff'
echo -e "\n${YELLOW}--- Diferencias encontradas (si las hay) ---${NC}"
diff_output=$(diff -u "$TEMP_EXPECTED_LOG" "$TEMP_ACTUAL_LOG")

if [ $? -eq 0 ]; then
    echo -e "${GREEN}  [OK] La salida de tu programa coincide con el log de referencia (ignorando timestamps).${NC}"
    TEST_RESULT=0
else
    echo -e "${RED}  [ERROR] La salida de tu programa NO coincide con el log de referencia (ignorando timestamps).${NC}"
    echo "$diff_output"
    TEST_RESULT=1
fi

# 5. Limpiar archivos temporales
rm -f "$TEMP_EXPECTED_LOG" "$TEMP_ACTUAL_LOG"

# --- Limpieza final del proyecto ---
echo -e "\n${GREEN}--- Limpiando archivos objeto y ejecutable del proyecto ---${NC}"
make fclean -C "${PROJECT_DIR}"

echo -e "\n${GREEN}--- Fin de las pruebas de ${EXEC_NAME} ---${NC}"

exit $TEST_RESULT
