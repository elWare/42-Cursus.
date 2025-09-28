# Makefile para el proyecto C++ Módulo 00/01 - ex02: Account Class

# -------------------------------------------------------------------------- #
# VARIABLES
# -------------------------------------------------------------------------- #

# Nombre del ejecutable final
NAME = accounts

# Compilador C++
CXX = g++

# Banderas del compilador (obligatorias en 42)
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g

# Archivos fuente (.cpp) de tu proyecto
SRCS = Account.cpp main.cpp

# Archivos objeto (.o)
OBJS = $(SRCS:.cpp=.o)

# Comando para eliminar archivos
RM = rm -f

# -------------------------------------------------------------------------- #
# REGLAS (Targets)
# -------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re