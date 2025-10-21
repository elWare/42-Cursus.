# Makefile para el proyecto C++ Módulo 00 - ex00: megaphone

# -------------------------------------------------------------------------- #
# VARIABLES
# -------------------------------------------------------------------------- #

# Nombre del ejecutable final
NAME = sed_for_losers

# Compilador C++ (¡siempre g++ para C++ en 42!)
CXX = g++

# Banderas del compilador (¡obligatorias y estrictas en 42!)
# -Wall: Habilita muchas advertencias.
# -Werror: Convierte todas las advertencias en errores (¡no compila con warnings!).
# -Wextra: Habilita advertencias adicionales.
# -std=c++98: Especifica el estándar C++98.
# -g: Incluye información de depuración para usar con gdb.
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g

# Archivos fuente (.cpp) de tu proyecto
SRCS = main.cpp

# Archivos objeto (.o) que se generarán a partir de los .cpp
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

# Regla 'all': El objetivo principal. Construye el ejecutable.
# Cuando haces 'make' (sin argumentos), esta regla se ejecuta por defecto [1].
all: $(NAME)

# Regla para construir el ejecutable final ($(NAME))
# Depende del archivo objeto megaphone.o.
# La receta enlaza el .o con el compilador C++ para crear el ejecutable.
$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

# Regla genérica para compilar archivos .cpp en .o
# Esto es una "regla de patrón". Dice: "Para cualquier archivo .o (%.o) que
# depende de un archivo .cpp (%.cpp) con el mismo nombre, ejecuta esta receta."
# $< : La primera dependencia (el archivo .cpp).
# $@ : El nombre del objetivo (el archivo .o).
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla 'clean': Elimina los archivos objeto (.o).
# Pero deja el ejecutable [1].
clean:
	$(RM) $(OBJS)

# Regla 'fclean': "Full clean". Elimina los archivos objeto (.o) Y el ejecutable.
# Deja el directorio como si nunca hubieras compilado nada [1].
fclean: clean
	$(RM) $(NAME)

# Regla 're': "Rehacer" el proyecto.
# Elimina todo (fclean) y luego lo vuelve a construir (all).
# Muy útil para asegurar una compilación limpia después de muchos cambios.
re: fclean all

# -------------------------------------------------------------------------- #
# REGLA PARA VALGRIND
# -------------------------------------------------------------------------- #

valgrind: $(NAME)
	@echo -e "\n${YELLOW}--- Ejecutando Valgrind para $(NAME) ---${NC}"
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./"$(NAME)"

.PHONY: all clean fclean re valgrind