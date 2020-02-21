/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** save and load map
*/

#include <stdio.h>
#include "my_world.h"

static int load_map_array(FILE *file, my_world_t *my_world)
{
    printf("%d\n", my_world->scale.y);
    my_world->map = malloc(sizeof(int *) * (my_world->scale.y + 1));
    if (my_world->map == NULL)
        return EXIT_ERROR;
    for (int y = 0; y < my_world->scale.y; y++) {
        my_world->map[y] = malloc(sizeof(int) * my_world->scale.x);
        if (my_world->map[y] == NULL
        || fread(my_world->map[y], sizeof(int), my_world->scale.x, file) <= 0)
            return EXIT_ERROR;
    }
    my_world->map[my_world->scale.y] = NULL;
    return EXIT_SUCCESS;
}

my_world_t *load_map(char *filepath)
{
    my_world_t *my_world = malloc(sizeof(my_world_t));
    FILE *file = fopen(filepath, "r");

    if (file == NULL || my_world == NULL)
        return NULL;
    if (fread(my_world, sizeof(my_world_t), 1, file) <= 0) {
        fclose(file);
        return NULL;
    }
    if (load_map_array(file, my_world) != EXIT_SUCCESS) {
        fclose(file);
        return NULL;
    }
    fclose(file);
    my_world->textures = get_textures();
    return my_world;
}

static int save_map_array(FILE *file, int **map, sfVector2i scale)
{
    for (int y = 0; y < scale.y; y++)
        if (fwrite(map[y], sizeof(int), scale.x, file) <= 0)
            return EXIT_ERROR;
    return EXIT_SUCCESS;
}

int save_map(char *filepath, my_world_t *my_world)
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