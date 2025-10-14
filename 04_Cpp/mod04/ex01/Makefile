NAME = worldOnFire
TITLE = "🔥 [CPP_04] [EX01] I don't want to set the world on fire "

SRC = Animal.cpp \
	  Brain.cpp \
	  Cat.cpp \
	  Dog.cpp \
	  main.cpp
		
OBJ = $(SRC:.cpp=.o)

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


CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling" $(TITLE) "🛠️"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "$(NAME) is ready ✅"

clean:
	@echo "Cleaning object files 🧹"
	@rm -rf $(OBJ)
	@echo "Object files cleaned ✅"

fclean: clean
	@echo "Cleaning executable and object files 🗑️"
	@rm -rf $(NAME)
	@echo "Executable and object files cleaned ✅"

re: fclean all
	@echo "Rebuilding $(TITLE) ♻️"

run: $(NAME)
	@echo "Running $(NAME) ▶️"
	@./$(NAME)
	@echo "Execution finished."

.PHONY: all clean fclean re run
