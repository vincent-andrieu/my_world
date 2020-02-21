/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

sfVector2f **water_gest(my_world_t *my_world)
{
    sfVector2f **map;
    int **temp = dup_map(my_world, 0, 0);

    for (int i = 0; i < my_world->scale.y; i++)
        for (int x = 0; x < my_world->scale.x; x++)
            temp[i][x] = (temp[i][x] <= WATER_LEVEL) ? WATER_LEVEL : temp[i][x];
    map = create_twod_map(temp, my_world);
    free_my_tab(temp);
    return map;
}

void draw_water(assets_t *assets, sfVector2f **map, my_world_t *my_world)
{
    for (int y = 0; y < my_world->scale.y; y++)
        for (int x = 0; x < my_world->scale.x; x++)
            if (my_world->map[y][x] < WATER_LEVEL)
                water_textures(my_world, map,
                    (sfVector2i) {x, y}, assets->window);
    free_my_map(map);
}