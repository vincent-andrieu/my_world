/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

int **dup_map(my_world_t *my_world, int size_x, int size_y)
{
    int **temp = malloc(sizeof(int *) * ((int) my_world->scale.y + size_y + 1));

    if (!temp)
        return NULL;
    temp[(int) my_world->scale.y + size_y] = NULL;
    for (int i = 0; i < my_world->scale.y + size_y; i++) {
        temp[i] = malloc(sizeof(int) * ((int) my_world->scale.x + size_x));
        if (!temp[i])
            return NULL;
        if (i < my_world->scale.y)
            for (int x = 0; x < my_world->scale.x + size_x; x++) {
                temp[i][x] = (x < my_world->scale.x) ? my_world->map[i][x] : 0;
            }
        else {
            for (int x = 0; x < my_world->scale.x + size_x; x++)
                temp[i][x] = 0;
        }
    }
    return temp;
}

void free_my_tab(int **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

int get_resize_map(my_world_t *my_world, int size_x, int size_y)
{
    int **temp;

    if (my_world->scale.y + size_y <= 0 || my_world->scale.x + size_x <= 0)
        return EXIT_ERROR;
    temp = dup_map(my_world, size_x, size_y);
    if (!temp)
        return EXIT_ERROR;
    free_my_tab(my_world->map);
    my_world->map = temp;
    my_world->scale.y += size_y;
    my_world->scale.x += size_x;
    return EXIT_SUCCESS;
}