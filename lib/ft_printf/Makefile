NAME = libftprintf.a

SRCS = ./srcs/ft_printf.c ./srcs/ft_strs.c ./srcs/ft_unints.c \
           ./srcs/ft_nums.c ./srcs/ft_putchar.c ./srcs/ft_pointers.c \
           ./srcs/ft_hexadecimal.c ./srcs/ft_hexxadecimal.c


OBJS = $(SRCS:.c=.o)
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re