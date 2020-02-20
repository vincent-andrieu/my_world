/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

static textures_t get_textures(void)
{
    textures_t textures;
    sfRenderStates *states[5] = {&textures.grass, &textures.dirt, &textures.stone,
                        &textures.snow, &textures.water};
    char const *paths[5] = {"./ressources/grass.png", "./ressources/dirt.png",
                            "./ressources/stone.png", "./ressources/snow.png",
                            "./ressources/water.png"};

    for (int i = 0; i < 5; i++) {
        states[i]->texture = sfTexture_createFromFile(paths[i], NULL);
        states[i]->blendMode = sfBlendAlpha;
        states[i]->transform = sfTransform_Identity;
        states[i]->shader = NULL;
    }
    return textures;
}

my_world_t *get_my_world(void)
{
    my_world_t *my_world = malloc(sizeof(my_world_t));

    if (!my_world)
        return NULL;
    my_world->scale = (sfVector2f) {MAP_X, MAP_Y};
    my_world->pos = (sfVector2i) {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 4};
    my_world->map = malloc(sizeof(int *) * (MAP_Y + 1));
    my_world->textures = get_textures();
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

