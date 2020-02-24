##
## EPITECH PROJECT, 2019
## makefile
## File description:
## project makefile
##

SRC	=	src/button/shape_button.c 	\
		src/button/button_manage.c 	\
		src/button/button_init.c 	\
		src/button/button_action.c 	\
		src/button/button_time.c 	\
		src/main.c 	\
		src/usage.c 	\
		src/my_world.c 	\
		src/print_map.c 	\
		src/textures.c 	\
		src/song_manage.c 	\
		src/struct_init.c 	\
		src/edit_map.c 	\
		src/map_resize.c 	\
		src/move_map.c 	\
		src/manage_floats.c 	\
		src/my_put_fdnbr.c 	\
		src/input.c 	\
		src/load.c 	\
		src/save.c 	\
		src/draw_water.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_world

CFLAGS	+=	-I include -Wall -Wextra -g
LDFLAGS +=	-L lib/my -lmy -L lib/graph -lgraph -lm

CC	=	gcc -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	make -C lib/graph/
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean