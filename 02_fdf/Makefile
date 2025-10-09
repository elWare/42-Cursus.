# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 16:04:22 by qmuntada          #+#    #+#              #
#    Updated: 2025/03/24 11:28:26 by jumarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** NAMES ***************************************************************** #

NAME = fdf
NAME_BONUS = fdf_bonus

# ***** VALUES ************************************************************** #

CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g
AR 				= ar rcs
RM 				= rm -f
MK 				= make -C
MKD				= mkdir -p

# ***** DIRECTORIES ********************************************************** #

SRC = src/fdf.c \
	src/color.c \
	src/command.c \
	src/display.c \
	src/draw.c \
	src/env.c \
	src/heigh.c \
	src/isometric.c \
	src/error.c \
	src/clean.c

SRC_BONUS = src_bonus/fdf_bonus.c \
			src_bonus/clean_bonus.c \
			src_bonus/color_bonus.c \
			src_bonus/command_bonus.c \
			src_bonus/display_bonus.c \
			src_bonus/draw_bonus.c \
			src_bonus/draw_triangle_bonus.c \
			src_bonus/env_bonus.c \
			src_bonus/error_bonus.c \
			src_bonus/eventkey_bonus.c \
			src_bonus/heigh_bonus.c \
			src_bonus/isometric_bonus.c \
			src_bonus/parallel_bonus.c

OBJS_DIR			= ./objs
OBJS_BONUS_DIR		= ./objs_bonus
LIBFT_DIR			= ./libft
MINILIBX_DIR		= ./minilibx-linux
INCLUDE				= ./include
LIBX = -L/usr/lib/X11 -lX11 -lXext -lXrandr -lXrender -lXfixes -lm

OBJ = $(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRC))
OBJ_BONUS = $(patsubst src_bonus/%.c, $(OBJS_BONUS_DIR)/%.o, $(SRC_BONUS))

# ***** RULES ***************************************************************** #

all: $(NAME)

$(NAME): cln_scr $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx_Linux.a $(OBJ)
	@echo "Creating executable of $(NAME) ..."
	$(CC) -o $(NAME) $(OBJ) -L$(MINILIBX_DIR) -lmlx -L$(LIBFT_DIR) -lft -I$(INCLUDE) $(LIBX)

$(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): cln_scr $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx_Linux.a $(OBJ_BONUS)
	@echo "Creating executable of $(NAME_BONUS) ..."
	$(CC) -o $(NAME_BONUS) $(OBJ_BONUS) -L$(MINILIBX_DIR) -lmlx -L$(LIBFT_DIR) -lft -I$(INCLUDE) $(LIBX)

$(OBJS_BONUS_DIR)/%.o: src_bonus/%.c | $(OBJS_BONUS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS_DIR):
	@mkdir -p $(OBJS_BONUS_DIR)

$(LIBFT_DIR)/libft.a:
	@echo "Compiling libft..."
	@$(MK) $(LIBFT_DIR)

$(MINILIBX_DIR)/libmlx_Linux.a:
	@echo "Compiling minilibx..."
	@$(MK) $(MINILIBX_DIR)

clean:
	@echo "Removing object files ..."
	@rm -rf $(OBJS_DIR) $(OBJS_BONUS_DIR)

fclean: clean
	@echo "Removing $(NAME) and $(NAME_BONUS) ..."
	@rm -rf $(NAME) $(NAME_BONUS)

cln_scr:
	@clear

re: fclean all

.PHONY: all bonus clean fclean re cln_scr