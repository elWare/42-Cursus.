# Makefile para el proyecto C++ Módulo 01 - ex01: Zombies

# -------------------------------------------------------------------------- #
# VARIABLES
# -------------------------------------------------------------------------- #

# Nombre del ejecutable final
NAME = ex02

# Compilador C++ (¡siempre g++ para C++ en 42!)
CXX = g++

# Banderas del compilador (¡obligatorias y estrictas en 42!)
# -Wall: Habilita muchas advertencias.
# -Werror: Convierte todas las advertencias en errores (¡no compila con warnings!).
# -Wextra: Habilita advertencias adicionales.
# -std=c++98: Especifica el estándar C++98 [1].
# -g: Incluye información de depuración para usar con gdb.
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g

# Archivos fuente (.cpp) de tu proyecto
# Aquí se listan TODOS los archivos .cpp que deben ser compilados.
SRCS = main.cpp

# Archivos objeto (.o) que se generarán a partir de los .cpp
OBJS = $(SRCS:.cpp=.o)

# Comando para eliminar archivos
RM = rm -f

# -------------------------------------------------------------------------- #
# REGLAS (Targets)
# -------------------------------------------------------------------------- #

# Regla 'all': El objetivo principal. Construye el ejecutable.
all: $(NAME)

# Regla para construir el ejecutable final ($(NAME))
$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

# Regla genérica para compilar archivos .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla 'clean': Elimina los archivos objeto (.o).
clean:
	$(RM) $(OBJS)

# Regla 'fclean': "Full clean". Elimina los archivos objeto (.o) Y el ejecutable.
fclean: clean
	$(RM) $(NAME)

# Regla 're': "Rehacer" el proyecto.
re: fclean all

# -------------------------------------------------------------------------- #
# REGLA PARA VALGRIND (¡NUEVA!)
# -------------------------------------------------------------------------- #

# Regla 'valgrind': Ejecuta el programa con Valgrind para detectar fugas de memoria.
# Depende de que el ejecutable $(NAME) esté construido.
valgrind: $(NAME)
	@echo -e "\n${YELLOW}--- Ejecutando Valgrind para detectar fugas de memoria ---${NC}" # Mensaje informativo
	# Los flags de Valgrind son cruciales para una detección completa:
	# --track-fds=yes : Rastrea descriptores de archivo abiertos/cerrados.
	# --leak-check=full : Realiza una verificación completa de fugas de memoria.
	# --show-leak-kinds=all : Muestra todos los tipos de fugas (definitely, indirectly, possibly).
	# --error-exitcode=1 : Hace que valgrind devuelva un código de error 1 si encuentra errores,
	#                      útil para scripts de automatización.
	# --suppressions=valgrind.supp : Opcional, para suprimir errores conocidos o que no son de tu código.
	# --quiet : Opcional, para una salida más concisa si no hay errores.
	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./"$(NAME)"

# Indicador de que estas reglas no son archivos reales (pseudo-objetivos).
.PHONY: all clean fclean re valgrind

# Colores para la salida del Makefile (opcional, pero útil)
# Se definen aquí para que puedan ser usadas en la regla valgrind
YELLOW='\033[0;33m'
NC='\033[0m'