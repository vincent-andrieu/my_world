##
## EPITECH PROJECT, 2019
## makefile
## File description:
## projects makefile
##

SRC	=	src/framebuffer_create.c	\
		src/framebuffer_destroy.c	\
		src/my_put_pixel.c	\
		src/my_draw_rect.c	\
		src/my_draw_line.c	\
		src/my_draw_rhombus.c	\
		src/my_draw_circle.c	\
		src/my_draw_batman.c	\
		src/my_get_pixel_color.c	\
		src/refresh_screen.c	\
		src/fill_background.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libgraph.a

CFLAGS  +=  -I ../../include -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean