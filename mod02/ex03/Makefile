# ---- MAKEFILE ----------------------------------------------------------------

NAME = bsp

TITLE = "🔥 [CPP_02] [EX03] BSP - Binary Space Partitioning "

SRC = bsp.cpp Fixed.cpp main.cpp Point.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++ # (o g++ si tu sistema lo usa por defecto, pero c++ suele apuntar a g++ o clang++)

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 # (Añadir -g para depuración)

# ---- rules -------------------------------------------------------------------

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(TITLE) 🛠️"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "$(NAME) is ready ✅"
	@echo ""
	@./$(NAME) # El makefile ejecuta el programa automáticamente después de compilar
	@echo ""
	@echo "Cleaning $(TITLE) 🧹"
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@echo "$(NAME) is cleaned ✅"

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