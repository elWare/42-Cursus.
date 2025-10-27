# ---- MAKEFILE ----------------------------------------------------------------

NAME = polymorphism # Nombre del ejecutable final
TITLE = "🔥 [CPP_04] [EX00] Polymorphism " # Título para mensajes en consola

SRC = Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		main.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp

OBJ = $(SRC:.cpp=.o) # Genera la lista de archivos objeto .o a partir de SRC

CXX = c++ # Compilador a usar
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 # Banderas de compilación

# ---- rules -------------------------------------------------------------------

# Regla para compilar archivos .cpp a .o (patrón)
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla por defecto: compila todo y crea el ejecutable
all: $(NAME)

# Regla para crear el ejecutable final (ahora solo compila y enlaza)
$(NAME): $(OBJ)
	@echo "Compiling $(TITLE) 🛠️"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "$(NAME) is ready ✅"

# .PHONY declara objetivos que no corresponden a nombres de archivos reales.
# Esto asegura que Make siempre ejecutará la regla aunque exista un archivo con ese nombre.
# Regla para limpiar archivos objeto
clean:
	@echo "Cleaning object files 🧹"
	@rm -rf $(OBJ) # Elimina todos los archivos .o
	@echo "Object files cleaned ✅"

# Regla para limpiar completamente (archivos objeto y ejecutable)
fclean: clean
	@echo "Cleaning executable and object files 🗑️"
	@rm -rf $(NAME) # Elimina el ejecutable
	@echo "Executable and object files cleaned ✅"

# Regla para reconstruir todo (limpiar completamente y luego compilar de nuevo)
re: fclean all
	@echo "Rebuilding $(TITLE) ♻️"

valgrind: $(NAME)
	@echo -e "\n${YELLOW}--- Ejecutando Valgrind para $(NAME) ---${NC}"
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./$(NAME)


# Regla para ejecutar el programa (asegurándose de que esté construido)
run: $(NAME)
	@echo "Running $(NAME) ▶️"
	@./$(NAME)
	@echo "Execution finished."

.PHONY: all clean fclean re valgrind run
# ---- colors ------------------------------------------------------------------

DEF_COLOR = \033[0m
BROWN   = \033[33;1m
MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
DARK_GREEN = \033[32;1m
WHITE   = \033[37;1m
GRAY    = \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD    = \033[1m
RED     = \033[31;1m
RESET   = \033[0m

# ---- end ---------------------------------------------------------------------