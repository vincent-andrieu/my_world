/*
** EPITECH PROJECT, 2019
** my_button
** File description:
** my_button
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

#ifndef MY_BUTTON_H
#define MY_BUTTON_H

typedef struct my_button_s {
    int tooggle;
    char *name;
    sfVector2f scale;
    sfVector2f pos;
    sfRectangleShape *button;
    sfRectangleShape *button_in;
    sfRectangleShape *button_ispressed;
    sfText *text;
    sfFont *font;
} my_button_t;

my_button_t *get_button(sfVector2f scale, sfVector2f pos);
void button_detroy(my_button_t *my_button);
void set_button_ispressed(my_button_t *my_button, sfColor back, sfColor front,
    float line_front_size);
void set_button_in(my_button_t *my_button, sfColor back, sfColor front,
    float line_front_size);
void set_button(my_button_t *my_button, sfColor back, sfColor front,
    float line_front_size);
void set_button_id(my_button_t *my_button, char *str, char *font_path,
    float size_char);
void button_refresh_stat(my_button_t *my_button, sfRenderWindow* window);
void button_display(my_button_t *my_button, sfRenderWindow *window);
bool button_ispressed(my_button_t *my_button);
void set_text_position_in_button(my_button_t *my_button, sfVector2f pos);

#endif