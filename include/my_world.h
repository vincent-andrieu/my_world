/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world .h file
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Audio.h>
#include <SFML/System/InputStream.h>
#include "my_button.h"
#include "graph.h"

#ifndef MY_WORLD_H_
#define MY_WORLD_H_

#define MSG_INVALID_ARG_NBR "Invalid arguments number\n"
#define EXIT_INVALID_ARG_NBR 84
#define EXIT_ERROR 84

#define ANGLE_X 0.785398
#define ANGLE_Y 0.610865
#define MAP_X 10
#define MAP_Y 10
#define DISPLAY_X 32
#define DISPLAY_Y 32
#define MOUSE_ACC 20
#define EDIT_SPEED 2
#define MOVE_SPEED 50
#define MOUSE_SENSI 10.f

#define SNOW_LEVEL 100
#define STONE_LEVEL 40
#define GRASS_LEVEL 0
#define DIRT_LEVEL -25

typedef struct textures_s
{
    sfRenderStates grass;
    sfRenderStates dirt;
    sfRenderStates stone;
    sfRenderStates snow;
    sfRenderStates water;
} textures_t;

typedef struct my_world_s {
    int **map;
    float zoom;
    sfVector2f scale;
    sfVector2i pos;
    sfVector2i pres_pos;
    textures_t textures;
} my_world_t;

int usage(int exit_value, char *binary_name);
bool does_kill_prog(assets_t *assets, my_world_t *my_world);
int my_world(assets_t *assets);
my_world_t *get_my_world(void);
void my_world_destroy(my_world_t *my_world);
sfVector2f **create_twod_map(int **three_d_map, my_world_t *my_world);
void draw_twod_map(assets_t *assets, sfVector2f **map, my_world_t *my_world);
void calc_textures(my_world_t *my_world, sfVector2f **map,
                    sfVector2i coord, sfRenderWindow *window);
sfRenderStates *get_map_texture(int level, textures_t *textures);
void map_stay_in_window(my_world_t *my_world);
void edit_map(sfRenderWindow *window,
            my_world_t *my_world, sfVector2f **coords_map);
sfMusic *start_song(void);
void song_destroy(sfMusic *song);
void reset_map(my_world_t *my_world);
int get_resize_map(my_world_t *my_world, int size_x, int size_y);

#define TOOLS_X 1700
#define FONT_PATH "./ressources/ChunkfiveEx.ttf"
#define SIZE_CHAR 20

typedef struct button_manage_s
{
    my_button_shape_t *exit;
    my_button_shape_t *restart;
    my_button_shape_t *zoom_in;
    my_button_shape_t *zoom_out;
    my_button_shape_t *size_x_plus;
    my_button_shape_t *size_x_min;
    my_button_shape_t *size_y_plus;
    my_button_shape_t *size_y_min;
    my_button_shape_t *up;
    my_button_shape_t *down;
    my_button_shape_t *left;
    my_button_shape_t *right;
} button_manage_t;

button_manage_t *get_button_manage(void);
void refresh_struct(button_manage_t *button, assets_t *assets);
void destroy_struct(button_manage_t *button);
void display_struct(button_manage_t *button, assets_t *assets);
void button_effect(my_world_t *my_world, button_manage_t *button,
    assets_t *assets);

#endif