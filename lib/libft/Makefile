NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs

SRCS	= ft_atoi.c ft_split.c ft_strlen.c ft_strnstr.c ft_strncmp.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

.PHONY: all clean fclean re bonus

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: clean all