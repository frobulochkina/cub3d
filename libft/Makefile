NAME = libft.a

SRCS = ft_strchr.c	ft_strlen.c	ft_strncmp.c	ft_strjoin.c	ft_split.c ft_strdup.c	ft_substr.c
OBJ = ft_strchr.o	ft_strlen.o	ft_strncmp.o	ft_strjoin.o	ft_split.o ft_strdup.o	ft_substr.o

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) libft.h
	ar rc $(NAME) $(OBJ)

bonus:	$(OBJ) libft.h
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
