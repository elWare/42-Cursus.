# Makefile para el proyecto C++ Módulo 03 - ex00: ClapTrap

# -------------------------------------------------------------------------- #
# VARIABLES
# -------------------------------------------------------------------------- #

NAME = claptrap
TITLE = "🔥 [CPP_03] [EX00] Aaaaand... OPEN! "
SRC = ClapTrap.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++ 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g # Incluye -g para depuración

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

%.o: %.cpp
	@echo -e "${BLUE}Compiling $<...${NC}"
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e "${GREEN}Linking $(NAME) 🔗 ${NC}"
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)
	@echo -e "${GREEN}$(NAME) is ready ✅${NC}"

clean:
	@echo -e "${RED}Cleaning object files 🧹 ${NC}"
	$(RM) $(OBJ)

fclean: clean
	@echo -e "${RED}Cleaning executable $(NAME) 🗑️ ${NC}"
	$(RM) $(NAME)

re: fclean all

# --- Nueva regla: 'run' para ejecutar el programa ---
run: $(NAME)
	@echo -e "${YELLOW}--- Running $(NAME) ---${NC}"
	./$(NAME)

# --- Nueva regla: 'valgrind' para verificar memoria ---
valgrind: $(NAME)
	@echo -e "\n${YELLOW}--- Ejecutando Valgrind para $(NAME) ---${NC}"
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./"$(NAME)"

.PHONY: all clean fclean re run valgrind