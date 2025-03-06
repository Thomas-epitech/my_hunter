##
## EPITECH PROJECT, 2024
## my hunter
## File description:
## lib Makefile
##

CC = gcc

NAME = libhunter.a

SRC = my_putstr.c \
	  get_random_float.c \
	  my_strcmp.c	\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
