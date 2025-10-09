# Makefile para el proyecto ex01: My Awesome PhoneBook

# -------------------------------------------------------------------------- #
# VARIABLES
# -------------------------------------------------------------------------- #

# Nombre del ejecutable final (el que vas a correr: ./phonebook)
NAME = phonebook

# Compilador C++ (¡usa g++ para C++!)
CXX = g++

# Banderas del compilador (¡obligatorias en 42!)
# -Wall: Habilita muchas advertencias.
# -Werror: Convierte todas las advertencias en errores (¡tu programa no compila con warnings!).
# -Wextra: Habilita aún más advertencias.
# -std=c++98: Especifica el estándar C++98 (el que se suele usar en los primeros módulos de 42).
# -g: Incluye información de depuración para usar con herramientas como gdb (¡muy útil!).
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g

# Archivos fuente (.cpp) de tu proyecto
# Aquí se listan todos los archivos .cpp que deben ser compilados.
# En tu caso, Contact.cpp y main.cpp son los que tienen implementaciones.
SRCS = PhoneBook.cpp Contact.cpp main.cpp

# Archivos objeto (.o) que se generarán a partir de los .cpp
# make automáticamente convierte .cpp a .o usando la regla genérica.
OBJS = $(SRCS:.cpp=.o)

# Comando para eliminar archivos (usado en clean y fclean)
RM = rm -f

# -------------------------------------------------------------------------- #
# REGLAS (Targets)
# -------------------------------------------------------------------------- #

# Regla 'all': El objetivo principal. Construye el ejecutable.
# Cuando haces 'make', esta regla se ejecuta por defecto.
all: $(NAME)

# Regla para construir el ejecutable final ($(NAME))
# Depende de todos los archivos objeto (.o).
# La receta enlaza todos los .o con el compilador C++ para crear el ejecutable.
$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

# Regla genérica para compilar archivos .cpp en .o
# Esto es una "regla de patrón". Dice: "Para cualquier archivo .o (%.o) que depende de un archivo .cpp (%.cpp) con el mismo nombre, ejecuta esta receta."
# $< : La primera dependencia (el archivo .cpp).
# $@ : El nombre del objetivo (el archivo .o).
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla 'clean': Elimina los archivos objeto (.o).
# Pero deja el ejecutable.
clean:
	$(RM) $(OBJS)

# Regla 'fclean': Elimina los archivos objeto (.o) Y el ejecutable.
# "Full clean". Deja el directorio como si nunca hubieras compilado.
fclean: clean
	$(RM) $(NAME)

# Regla 're': "Rehacer" el proyecto.
# Elimina todo (fclean) y luego lo vuelve a construir (all).
# Muy útil para asegurar una compilación limpia después de muchos cambios.
re: fclean all

# Indicador de que estas reglas no son archivos reales (pseudo-objetivos).
# Esto evita que make intente crear archivos con estos nombres si existen.
.PHONY: all clean fclean re