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

static bool check_diff(int **map, sfVector2i from, sfVector2i to)
{
    int diff = map[from.y][from.x] - map[to.y][to.x];

    if ((diff < 0 ? -diff : diff) > 30) {
        map[from.y][from.x] = (map[from.y][from.x] + map[to.y][to.x]) / 2;
        map[to.y][to.x] = (map[from.y][from.x] + map[to.y][to.x]) / 2;
        smooth_map(map);
        return true;
    }
    return false;
}

void smooth_map(int **map)
{
    for (int y = 0; y < MAP_Y - 1; y++)
        for (int x = 0; x < MAP_X - 1; x++)
            if (check_diff(map, (sfVector2i) {y, x}, (sfVector2i) {y + 1, x})
            || check_diff(map, (sfVector2i) {y, x}, (sfVector2i) {y, x + 1})) {
                smooth_map(map);
                return;
            }
}