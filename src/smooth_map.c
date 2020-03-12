/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** smooth map
*/

#include "my_world.h"

bool already_exist(int *tab, int value, int max)
{
    for (int i = 0; i < max; i++)
        if (tab[i] == value)
            return true;
    return false;
}

static bool check_diff(my_world_t *my_world, sfVector2i from, sfVector2i to)
{
    int diff = my_world->map[from.y][from.x] - my_world->map[to.y][to.x];

    if ((diff < 0 ? -diff : diff) > 35) {
        my_world->map[from.y][from.x]
            = (my_world->map[from.y][from.x] + my_world->map[to.y][to.x]) / 2;
        my_world->map[to.y][to.x]
            = (my_world->map[from.y][from.x] + my_world->map[to.y][to.x]) / 2;
        smooth_map(my_world);
        return true;
    }
    return false;
}

void smooth_map(my_world_t *my_world)
{
    for (int y = 0; y < my_world->scale.x - 1; y++)
        for (int x = 0; x < my_world->scale.y - 1; x++)
            if (check_diff(my_world, (sfVector2i) {y, x},
                            (sfVector2i) {y + 1, x})
            || check_diff(my_world, (sfVector2i) {y, x},
                            (sfVector2i) {y, x + 1})) {
                smooth_map(my_world);
                return;
            }
}