/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** save and load map
*/

#include <stdio.h>
#include "my_world.h"

static int save_map_array(FILE *file, int **map, sfVector2i scale)
{
    for (int y = 0; y < scale.y; y++)
        if (fwrite(map[y], sizeof(int), scale.x, file) <= 0)
            return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int save_map(char *filepath, my_world_t *my_world)
{
    FILE *file = fopen(filepath, "w");

    if (file == NULL)
        return EXIT_ERROR;
    if (fwrite(my_world, sizeof(my_world_t), 1, file) <= 0)
        return EXIT_ERROR;
    if (save_map_array(file, my_world->map, my_world->scale) != EXIT_SUCCESS)
        return EXIT_ERROR;
    fclose(file);
    return EXIT_SUCCESS;
}

int button_save(my_world_t *my_world, button_manage_t *button)
{
    char *filepath;

    if (button_ispressed(button->save) && button->save->is_activate) {
        filepath = get_input();
        if (filepath == NULL)
            return EXIT_ERROR;
        if (save_map(filepath, my_world) != EXIT_SUCCESS)
            return EXIT_ERROR;
        free(filepath);
        button->save->is_activate = false;
    }
    return EXIT_SUCCESS;
}