/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world .h file
*/

#include <stdlib.h>
#include <stdbool.h>
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

typedef struct my_world_s {
    int **map;
    sfVector2f scale;
    sfVector2i pos;
} my_world_t;

int usage(int exit_value, char *binary_name);
bool does_kill_prog(assets_t *assets);
int my_world(assets_t *assets);
int bootstrap(assets_t *assets);
my_world_t *get_my_world(void);
void my_world_destroy(my_world_t *my_world);
sfVector2f **create_twod_map(int **three_d_map, sfVector2i pos);
int draw_twod_map(sfRenderWindow *window, sfVector2f **map);

#endif