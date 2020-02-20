/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

static void set_val(my_world_t *my_world)
{
    my_world->scale.x = MAP_X;
    my_world->scale.y = MAP_Y;
    my_world->pos.x = WINDOW_WIDTH / 2;
    my_world->pos.y = WINDOW_HEIGHT / 4;
    my_world->zoom = 1;
}

my_world_t *get_my_world(void)
{
    my_world_t *my_world = malloc(sizeof(my_world_t));

    if (!my_world)
        return NULL;
    set_val(my_world);
    my_world->map = malloc(sizeof(int *) * (MAP_Y + 1));
    if (!my_world->map)
        return NULL;
    my_world->map[MAP_Y] = NULL;
    for (int y = 0; y < MAP_Y; y++) {
        my_world->map[y] = malloc(sizeof(int) * MAP_X);
        if (!my_world->map[y])
            return NULL;
        for (int x = 0; x < MAP_X; x++)
            my_world->map[y][x] = 0;
    }
    return my_world;
}

void my_world_destroy(my_world_t *my_world)
{
    for (int i = 0; my_world->map[i]; i++)
        free(my_world->map[i]);
    free(my_world->map);
    free(my_world);
}

