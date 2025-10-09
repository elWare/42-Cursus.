NAME = libftprintf.a

SRCS = ft_printf.c\
ft_printdiu.c\
ft_printhex.c\
ft_printptr.c\
ft_printc.c\
ft_prints.c\
ft_uitoa.c

OBJS = $(SRCS:.c=.o)
LIBFT = ../libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

all: $(NAME)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	make -C ../libft

clean:
	make clean -C ../libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C ../libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
