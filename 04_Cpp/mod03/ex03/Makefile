# ---- MAKEFILE ----------------------------------------------------------------

NAME = diamond

TITLE = "🔥 [CPP_03] [EX03] Now it's weird! "

SRC = main.cpp \
	ClapTrap.cpp \
	DiamondTrap.cpp \
	FragTrap.cpp \
	ScavTrap.cpp

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

all: $(NAME)

$(NAME): $(OBJ)
	@echo ${GREEN}Compiling $(TITLE) 🛠️${NC}
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "${GREEN}$(NAME) is ready ✅${NC}"

%.o: %.cpp
	@echo  "${BLUE}Compiling $<...${NC}"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo  "${RED}Cleaning object files 🧹 ${NC}"
	@$(RM) $(OBJ)

fclean: clean
	@echo  "${RED}Cleaning executable $(NAME) 🗑️ ${NC}"
	@$(RM) $(NAME)

re: fclean all

run: $(NAME)
	@echo  "\n${YELLOW}--- Running $(NAME) ---${NC}"
	@./$(NAME)
	@echo  "\n${YELLOW}--- Program finished ---${NC}"

valgrind: $(NAME)
	@echo  "\n${YELLOW}--- Running Valgrind for $(NAME) ---${NC}"
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./"$(NAME)"

.PHONY: all clean fclean re run valgrind
