/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

static sfVector2f get_max_in_map(my_world_t *my_world, sfVector2f **my_map)
{
    float max_x = 0;
    float max_y = 0;

    for (int y = 0; y < my_world->scale.y; y++)
        for (int x = 0; x < my_world->scale.x; x++) {
            max_x = (my_map[y][x].x > max_x) ? my_map[y][x].x : max_x;
            max_y = (my_map[y][x].y > max_y) ? my_map[y][x].y : max_y;
        }
    return (sfVector2f) {max_x, max_y};
}

static sfVector2f get_min_in_map(my_world_t *my_world, sfVector2f **my_map)
{
    float min_x = 0;
    float min_y = 0;

    for (int y = 0; y < my_world->scale.y; y++)
        for (int x = 0; x < my_world->scale.x; x++) {
            min_x = (my_map[y][x].x < min_x) ? my_map[y][x].x : min_x;
            min_y = (my_map[y][x].y < min_y) ? my_map[y][x].y : min_y;
        }
    return (sfVector2f) {min_x, min_y};
}

void map_stay_in_window(my_world_t *my_world)
{
    sfVector2f **my_map = create_twod_map(my_world->map, my_world->pos);
    sfVector2f min;
    sfVector2f max;

    if (!my_map)
        return;
    min = get_min_in_map(my_world, my_map);
    max = get_max_in_map(my_world, my_map);
    if (min.y < 0 || min.x < 0 || max.x > WINDOW_WIDTH || max.y > WINDOW_HEIGHT)
        my_world->pos = my_world->pres_pos;
    for (int i = 0; my_map[i]; i++)
        free(my_map[i]);
    free(my_map);
}