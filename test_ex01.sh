#!/bin/bash

# --- Configuración ---
EXEC_NAME="phonebook" # Nombre de tu ejecutable PhoneBook
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# --- Limpiar y compilar ---
echo -e "${GREEN}--- Compilando $EXEC_NAME ---${NC}"
make re -C ex01 # Asume que tu Makefile está en el directorio 'ex01'
if [ $? -ne 0 ]; then
    echo -e "${RED}Error de compilación para $EXEC_NAME. Abortando pruebas.${NC}"
    exit 1
fi
echo -e "${GREEN}Compilación exitosa.${NC}"

# Verificar si el ejecutable existe
if [ ! -f "ex01/$EXEC_NAME" ]; then
    echo -e "${RED}El ejecutable $EXEC_NAME no se encontró en ex01/. Asegúrate de que tu Makefile lo cree allí.${NC}"
    exit 1
fi

# --- PRUEBA 1: Añadir y Buscar contactos básicos ---
echo -e "\n${GREEN}--- PRUEBA 1: Añadir 2 contactos y Búsqueda básica ---${NC}"
INPUT_SEQUENCE_1=$(cat <<EOF
ADD
Alice
Smith
Ali
111-222-3333
Le gusta el queso
ADD
Bob
Johnson
Bobby
444-555-6666
Es alérgico a los gatos
SEARCH
0
EXIT
EOF
)

echo "Ejecutando: ./ex01/$EXEC_NAME con secuencia 1..."
OUTPUT_1=$(echo "$INPUT_SEQUENCE_1" | ./ex01/$EXEC_NAME)
echo "$OUTPUT_1"

# --- Validaciones para PRUEBA 1 ---
if echo "$OUTPUT_1" | grep -q "Primer Nombre: Alice"; then
    echo -e "${GREEN}  [OK] Contacto Alice encontrado en detalles.${NC}"
else
    echo -e "${RED}  [ERROR] Contacto Alice NO encontrado en detalles.${NC}"
fi

if echo "$OUTPUT_1" | grep -q "Apellidos:     Smith"; then
    echo -e "${GREEN}  [OK] Apellidos de Alice correctos.${NC}"
else
    echo -e "${RED}  [ERROR] Apellidos de Alice incorrectos.${NC}"
fi

if echo "$OUTPUT_1" | grep -q "Total de contactos activos: 2"; then
    echo -e "${GREEN}  [OK] Contador de contactos correcto (2).${NC}"
else
    echo -e "${RED}  [ERROR] Contador de contactos incorrecto.${NC}"
fi

# --- PRUEBA 2: Límite de 8 contactos y reemplazo ---
echo -e "\n${GREEN}--- PRUEBA 2: Añadir 9 contactos (verificar reemplazo y búsqueda) ---${NC}"
# Añadimos 9 contactos, el primero (Alice) debería ser reemplazado
INPUT_SEQUENCE_2=$(cat <<EOF
ADD
Alice_OLD
Smith_OLD
Ali_OLD
000
Secreto_viejo
ADD
Bob
Johnson
Bobby
1
Secreto1
ADD
Charlie
Brown
Chuck
2
Secreto2
ADD
David
Clark
Dave
3
Secreto3
ADD
Eve
Davis
Evie
4
Secreto4
ADD
Frank
Miller
Franky
5
Secreto5
ADD
Grace
Wilson
Gracie
6
Secreto6
ADD
Heidi
Moore
Hiddy
7
Secreto7
ADD
Ivan
Taylor
Ivy
8
Secreto8
SEARCH
0
SEARCH
8
EXIT
EOF
)

echo "Ejecutando: ./ex01/$EXEC_NAME con secuencia 2 (9 ADDs)..."
OUTPUT_2=$(echo "$INPUT_SEQUENCE_2" | ./ex01/$EXEC_NAME)
echo "$OUTPUT_2"

# --- Validaciones para PRUEBA 2 ---
echo -e "${YELLOW}  (El contacto Alice_OLD en índice 0 debería haber sido reemplazado por Ivan){NC}"
if echo "$OUTPUT_2" | grep -q "Primer Nombre: Ivan"; then
    echo -e "${GREEN}  [OK] Contacto Ivan (índice 0) correcto (reemplazo).${NC}"
else
    echo -e "${RED}  [ERROR] Contacto Ivan (índice 0) NO correcto (reemplazo fallido).${NC}"
fi

if echo "$OUTPUT_2" | grep -q "Total de contactos activos: 8"; then
    echo -e "${GREEN}  [OK] Contador de contactos correcto (8).${NC}"
else
    echo -e "${RED}  [ERROR] Contador de contactos incorrecto después de 9 ADDs.${NC}"
fi

if echo "$OUTPUT_2" | grep -q "Índice inválido. Por favor, introduce un índice entre 0 y 7"; then
    echo -e "${GREEN}  [OK] Manejo de búsqueda de índice fuera de rango correcto (8).${NC}"
else
    echo -e "${RED}  [ERROR] Fallo en el manejo de búsqueda de índice fuera de rango (8).${NC}"
fi


# --- PRUEBA 3: Comandos inválidos y entradas vacías ---
echo -e "\n${GREEN}--- PRUEBA 3: Comandos inválidos y entradas vacías ---${NC}"
INPUT_SEQUENCE_3=$(cat <<EOF
INVALiDO
ADD
    
Alice
Smith
Ali
111
Secreto
SEARCH
99
SEARCH
a
EXIT
EOF
)

echo "Ejecutando: ./ex01/$EXEC_NAME con secuencia 3..."
OUTPUT_3=$(echo "$INPUT_SEQUENCE_3" | ./ex01/$EXEC_NAME)
echo "$OUTPUT_3"

# --- Validaciones para PRUEBA 3 ---
if echo "$OUTPUT_3" | grep -q "Comando inválido. Por favor, usa ADD, SEARCH o EXIT."; then
    echo -e "${GREEN}  [OK] Mensaje de comando inválido.${NC}"
else
    echo -e "${RED}  [ERROR] No se detectó comando inválido.${NC}"
fi

if echo "$OUTPUT_3" | grep -q "Comando inválido. Por favor, usa ADD, SEARCH o EXIT."; then
    echo -e "${GREEN}  [OK] Manejo de campo vacío en ADD.${NC}"
else
    echo -e "${RED}  [ERROR] Fallo en el manejo de campo vacío en ADD.${NC}"
fi

if echo "$OUTPUT_3" | grep -q "Índice inválido"; then
    echo -e "${GREEN}  [OK] Manejo de índice de búsqueda fuera de rango.${NC}"
else
    echo -e "${RED}  [ERROR] Fallo en el manejo de índice de búsqueda fuera de rango.${NC}"
fi

if echo "$OUTPUT_3" | grep -q "Entrada no numérica. Cancelando búsqueda."; then
    echo -e "${GREEN}  [OK] Manejo de entrada no numérica en búsqueda.${NC}"
else
    echo -e "${RED}  [ERROR] Fallo en el manejo de entrada no numérica en búsqueda.${NC}"
fi

# --- PRUEBA 4: Salida con EOF (Ctrl+D) ---
echo -e "\n${GREEN}--- PRUEBA 4: Salida con EOF (Ctrl+D) ---${NC}"
echo -e "Ejecutando: ./ex01/$EXEC_NAME con EOF (simulando Ctrl+D)..."
# Simular EOF simplemente terminando el "echo"
OUTPUT_4=$(echo "" | ./ex01/$EXEC_NAME)
echo "$OUTPUT_4"

if echo "$OUTPUT_4" | grep -q "EOF detectado. Saliendo del programa."; then
    echo -e "${GREEN}  [OK] Manejo de EOF correcto.${NC}"
else
    echo -e "${RED}  [ERROR] Fallo en el manejo de EOF.${NC}"
fi


# --- Limpieza al final ---
echo -e "\n${GREEN}--- Limpiando archivos objeto y ejecutable de $EXEC_NAME ---${NC}"
make fclean -C ex01

echo -e "\n${GREEN}--- Fin de las pruebas de $EXEC_NAME ---${NC}"
