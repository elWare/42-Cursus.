# Makefile para el proyecto C++ Módulo 01 - ex05: Harl 2.0

# -------------------------------------------------------------------------- #
# VARIABLES
# -------------------------------------------------------------------------- #

# Nombre del ejecutable final
NAME = harl

# Compilador C++ (¡g++ para C++ en 42!)
CXX = g++

# Banderas del compilador (obligatorias y estrictas en 42)
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g

# Archivos fuente (.cpp) de tu proyecto
SRCS = Harl.cpp main.cpp

# Archivos objeto (.o) que se generarán
OBJS = $(SRCS:.cpp=.o)

# Comando para eliminar archivos
RM = rm -f

# Colores para la salida del Makefile (opcional)
YELLOW='\033[0;33m'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# -------------------------------------------------------------------------- #
# REGLAS (Targets)
# -------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(OBJS)
	@echo -e "${GREEN}Enlazando $(NAME) 🔗 ${NC}"
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)
	@echo -e "${GREEN}$(NAME) está listo ✅${NC}"

%.o: %.cpp
	@echo -e "${YELLOW}Compilando $<...${NC}"
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo -e "${RED}Limpiando archivos objeto 🧹 ${NC}"
	$(RM) $(OBJS)

fclean: clean
	@echo -e "${RED}Limpiando ejecutable $(NAME) 🗑️ ${NC}"
	$(RM) $(NAME)

re: fclean all

# -------------------------------------------------------------------------- #
# REGLA PARA VALGRIND
# -------------------------------------------------------------------------- #

valgrind: $(NAME)
	@echo -e "\n${YELLOW}--- Ejecutando Valgrind para $(NAME) ---${NC}"
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./"$(NAME)"

.PHONY: all clean fclean re valgrind