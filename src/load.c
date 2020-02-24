/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** load the map
*/

#include <stdio.h>
#include "my_world.h"

static int load_map_array(FILE *file, my_world_t *my_world)
{
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

static my_world_t *load_map(FILE *file)
{
    my_world_t *my_world = malloc(sizeof(my_world_t));

    if (my_world == NULL || fread(my_world, sizeof(my_world_t), 1, file) <= 0) {
        fclose(file);
        return NULL;
    }
    if (load_map_array(file, my_world) == EXIT_ERROR) {
        fclose(file);
        return NULL;
    }
    fclose(file);
    my_world->textures = get_textures();
    return my_world;
}

int button_load(my_world_t **my_world, button_manage_t *button)
{
    char *filepath;
    FILE *file;

    if (button_ispressed(button->load) && button->load->is_activate) {
        filepath = get_input("Loading filepath");
        file = fopen(filepath, "r");
        free(filepath);
        if (file == NULL) {
            my_put_error_str("Bad loading filepath\n");
            return EXIT_FAILURE;
        }
        my_world_destroy(*my_world);
        *my_world = load_map(file);
        if (*my_world == NULL)
            return EXIT_ERROR;
        button->load->is_activate = false;
    }
    return EXIT_SUCCESS;
}