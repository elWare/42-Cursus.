# ***** NAMES ***************************************************************** #

NAME 			= push_swap
NAME_BONUS		= checker

# ***** APARIENCE ************************************************************* #

DEL_LINE 		= \033[2K
ITALIC 			= \033[3m
BOLD 			= \033[1m
DEF_COLOR 		= \033[0;39m
GRAY 			= \033[0;90m
RED 			= \033[0;91m
GREEN 			= \033[0;92m
YELLOW 			= \033[0;93m
BLUE 			= \033[0;94m
MAGENTA 		= \033[0;95m
CYAN 			= \033[0;96m
WHITE 			= \033[0;97m
BLACK 			= \033[0;99m
ORANGE 			= \033[38;5;209m
BROWN 			= \033[38;2;184;143;29m
DARK_GRAY 		= \033[38;5;234m
MID_GRAY 		= \033[38;5;245m
DARK_GREEN 		= \033[38;2;75;179;82m
DARK_YELLOW 	= \033[38;5;143m

# ***** VALUES ************************************************************** #

CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra -g
AR 				= ar rcs
RM 				= rm -f
MK 				= make -C
MKD				= mkdir -p
MCL 			= make clean -C
MFCL 			= make fclean -C
MK_				= && make

# ***** DIRECTORIES ********************************************************** #

SRCS			= src/ft_push.c \
				src/ft_rotate_down.c \
				src/ft_rotate_up.c \
				src/ft_swap.c \
				src/ft_tfind_index.c \
				src/ft_tfind.c \
				src/ft_tfree.c \
				src/ft_tindex.c \
				src/ft_tools.c \
				src/ft_tpos.c \
				src/ft_tsort_big.c \
				src/ft_tsort_c.c \
				src/ft_tsort.c \
				src/push_swap.c

SRCS_BONUS		= src/ft_push.c \
				src/ft_rotate_down.c \
				src/ft_rotate_up.c \
				src/ft_swap.c \
				src/ft_tfind_index.c \
				src/ft_tfind.c \
				src/ft_tfree.c \
				src/ft_tindex.c \
				src/ft_tools.c \
				src/ft_tpos.c \
				src/ft_tsort_big.c \
				src/ft_tsort_c.c \
				src/ft_tsort.c \
				src_bonus/checker_bonus.c \
				src_bonus/checker_utils_bonus.c \
				include/get_next_line/get_next_line.c \
				include/get_next_line/get_next_line_utils.c

OBJS			= $(SRCS:.c=.o)
OBJS_BONUS		= $(SRCS_BONUS:.c=.o)

OBJS_DIR		= ./objs
LIBFT_DIR		= ./include/libft
FT_PRINTF_DIR	= ./include/printf
INCLUDES		= ./include

all: $(NAME)

$(NAME): clean_screen $(OBJS) $(LIBFT_DIR)/libft.a $(FT_PRINTF_DIR)/libftprintf.a
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${LIBFT_DIR} -lft -L${FT_PRINTF_DIR} -lftprintf -I${INCLUDES}

$(LIBFT_DIR)/libft.a:
	@echo "${MAGENTA}${BOLD}Compiling my libft..."
	@${MAKE} -C ${LIBFT_DIR}
	@echo "${DEF_COLOR}"

$(FT_PRINTF_DIR)/libftprintf.a:
	@echo "${ORANGE}${BOLD}Compiling my ft_printf..."
	@${MAKE} -C ${FT_PRINTF_DIR}
	@echo "${DEF_COLOR}"

bonus: $(NAME_BONUS)

$(NAME_BONUS): clean_screen $(OBJS_BONUS)
	@echo "${DARK_YELLOW}${BOLD}Compiling my ${NAME_BONUS}...${DEF_COLOR}"
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -I$(INCLUDES)
	@echo "${DARK_GREEN}${BOLD}Compilation is done!${DEF_COLOR}"

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "${BLUE}${BOLD}Compiling $<...${DEF_COLOR}"

clean:
	@${RM} ${OBJS} ${OBJS_BONUS}
	@echo "${RED}${BOLD}Cleaning objects...${DEF_COLOR}"
	@${MCL} ${LIBFT_DIR}
	@${MCL} ${FT_PRINTF_DIR}
	@if [ -d "$(OBJS_DIR)" ]; then ${RM} -r $(OBJS_DIR); fi
	@echo "${RED}${BOLD}Cleaning objects is done!${DEF_COLOR}"
	#@${RM} -r ./objs
	#@echo "${RED}${BOLD}Cleaning objects is done!${DEF_COLOR}"

fclean: clean
	@${RM} ${NAME}
	@${RM} ${NAME_BONUS}
	@echo "${RED}${BOLD}Cleaning ${NAME}...${DEF_COLOR}"
	@${MFCL} $(LIBFT_DIR)
	@${MFCL} $(FT_PRINTF_DIR)
	@echo "${RED}${BOLD}Cleaning ${NAME} is done!${DEF_COLOR}"

clean_screen:
	@clear

re: fclean all

.PHONY: all clean fclean re libft ft_printf 
