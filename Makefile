##
## EPITECH PROJECT, 2024
## my hunter
## File description:
## Makefile
##

NAME	=	my_hunter

LIB_NAME = lib/hunter/libhunter.a

SRC	=	src/main.c	\
		src/ressource_loader.c	\
		src/game_loop.c	\
		src/window_rendering.c	\
		src/update_game/game_updating.c	\
		src/update_game/duck_updating.c	\
		src/update_game/music_updating.c	\
		src/update_game/level_updating.c	\
		src/update_game/alien_updating.c	\
		src/event_handling.c	\
		src/toggle_game_mode.c	\
		src/print_help_message.c	\
		src/destroyer.c	\


OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude/ -Wall -Wextra -lcsfml-graphics -lcsfml-window	\
			-lcsfml-system -lcsfml-audio -Llib/hunter -lhunter

all: $(LIB_NAME) $(NAME)

$(LIB_NAME):
	make -C lib/hunter

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
