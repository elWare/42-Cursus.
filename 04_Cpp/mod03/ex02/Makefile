# ---- MAKEFILE ----------------------------------------------------------------

NAME = fragtrap

TITLE = "🔥 [CPP_03] [EX02] Repetitive work "

# Archivos fuente (.cpp) de tu proyecto
# Incluye main.cpp, ClapTrap.cpp, FragTrap.cpp, y ScavTrap.cpp.
SRC = main.cpp \
		ClapTrap.cpp \
		FragTrap.cpp \
		ScavTrap.cpp

# Archivos objeto (.o) que se generarán
OBJ = $(SRC:.cpp=.o)

# Compilador C++
CXX = c++ 

# Banderas del compilador (obligatorias en 42)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g # Añadido -g para depuración

# Comando para eliminar archivos
RM = rm -f

# --- Colores para la salida del Makefile (opcional) ---
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m'
# -------------------------------------------------------------------------- #
# REGLAS (Targets)
# -------------------------------------------------------------------------- #

# Regla 'all': El objetivo principal. Construye el ejecutable.
all: $(NAME)

# Regla para construir el ejecutable final ($(NAME))
# Depende de todos los archivos objeto (.o). Esta es la fase de ENLAZADO.
$(NAME): $(OBJ)
	@echo  "${GREEN}Compiling $(TITLE) 🛠️${NC}"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo  "${GREEN}$(NAME) is ready ✅${NC}"

# Regla genérica para compilar archivos .cpp en .o
# Esta es la fase de COMPILACIÓN individual de cada archivo.
%.o: %.cpp
	@echo  "${BLUE}Compiling $<...${NC}"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla 'clean': Elimina los archivos objeto (.o).
clean:
	@echo  "${RED}Cleaning object files 🧹 ${NC}"
	@$(RM) $(OBJ)

# Regla 'fclean': "Full clean". Elimina los archivos objeto (.o) Y el ejecutable.
fclean: clean
	@echo  "${RED}Cleaning executable $(NAME) 🗑️ ${NC}"
	@$(RM) $(NAME)

# Regla 're': "Rehacer" el proyecto.
# Elimina todo (fclean) y luego lo vuelve a construir (all).
re: fclean all

# --- Regla 'run': Para ejecutar el programa explícitamente ---
# Depende de que el ejecutable $(NAME) esté construido.
run: $(NAME)
	@echo  "\n${YELLOW}--- Running $(NAME) ---${NC}"
	@./$(NAME)
	@echo  "\n${YELLOW}--- Program finished ---${NC}"

# --- Regla 'valgrind': Para verificar fugas de memoria ---
# Depende de que el ejecutable $(NAME) esté construido.
valgrind: $(NAME)
	@echo  "\n${YELLOW}--- Running Valgrind for $(NAME) ---${NC}"
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./"$(NAME)"

# Indicador de que estas reglas no son archivos reales (pseudo-objetivos).
.PHONY: all clean fclean re run valgrind
