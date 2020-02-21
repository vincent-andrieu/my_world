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

#define TIME_BUT 2.0f
#define NB_TEXTURE 3
#define HIT_X 216
#define HIT_Y 90

typedef struct my_button_shape_s {
    int toggle;
    char *name;
    sfVector2f pos;
    sfVector2f scale;
    sfText *text;
    sfFont *font;
    sfTexture **texture;
    sfClock *clock_start;
    bool is_pressed;
} my_button_shape_t;

my_button_shape_t *get_button_shape(sfVector2f pos, sfVector2f scale);
int set_texture_button(my_button_shape_t *my_button, char *path_one,
    char *path_two, char *path_three);
void button_shape_destroy(my_button_shape_t *my_button);
void button_refresh_stat(my_button_shape_t *my_button, sfRenderWindow *window);
void button_display(my_button_shape_t *my_button, sfRenderWindow *window);
bool button_ispressed(my_button_shape_t *my_button);
int set_button_id(my_button_shape_t *my_button, char *str, char *font_path,
    float size_char);
float as_seconds(sfTime time);
void button_status(int temp, my_button_shape_t *my_button);

#endif