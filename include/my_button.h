/*
** EPITECH PROJECT, 2019
** my_button
** File description:
** my_button
*/

#include <SFML/Graphics.h>
#include <SFML/Audio/Sound.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#define TIME_BUT 0.3f
#define NB_TEXTURE 3
#define HIT_X 216
#define HIT_Y 90
#define TOOLS_X 1700
#define FONT_PATH "./ressources/ChunkfiveEx.ttf"
#define SIZE_CHAR 20
#define HELP_BOX_CHAR_SIZE 25
#define HELP_BOX_X 10
#define HELP_BOX_Y 950

typedef struct sound_t
{
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_s;

typedef struct help_box_s
{
    sfFont *font;
    sfText *text;
    sfTexture *texture;
    sfSprite *sprite;
} help_box_t;

typedef struct my_button_shape_s {
    int toggle;
    char *name;
    sfVector2f pos;
    sfVector2f scale;
    sfText *text;
    sfFont *font;
    sfTexture **texture;
    sfClock *clock_start;
    sound_s sound;
    help_box_t help_box;
    bool is_pressed;
    bool is_activate;
} __attribute__((packed)) my_button_shape_t;

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