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
		src/button/sound.c 	\
		src/button/help_box.c 	\
		src/list.c 	\
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
		src/input.c 	\
		src/load.c 	\
		src/save.c 	\
		src/tiles_select.c 	\
		src/shadow.c 	\
		src/generate_map.c 	\
		src/display_something.c 	\
		src/event_input.c 	\
		src/draw_water.c 	\
		src/display_entity.c 	\
		src/dog.c 	\
		src/cube.c 	\
		src/cube_mode.c 	\
		src/display_face.c 	\
		src/get_h.c 	\
		src/time.c 	\
		src/smooth_map.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_world

CFLAGS	+=	-I include -Wall -Wextra
LDFLAGS +=	-L lib/my -lmy -L lib/graph -lgraph -lm

CC	=	gcc -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	make -C lib/graph/
	mkdir -p SAVES;$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean