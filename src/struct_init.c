/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

textures_t get_textures(void)
{
    textures_t textures;
    sfRenderStates *states[6] = {&textures.grass, &textures.dirt,
        &textures.stone, &textures.snow, &textures.water, &textures.sand};
    char const *paths[6] = {"./ressources/grass.png", "./ressources/dirt.png",
                            "./ressources/stone.png", "./ressources/snow.png",
                            "./ressources/water.png", "./ressources/sand.png"};

    for (int i = 0; i < 6; i++) {
        states[i]->texture = sfTexture_createFromFile(paths[i], NULL);
        states[i]->blendMode = sfBlendAlpha;
        states[i]->transform = sfTransform_Identity;
        states[i]->shader = NULL;
    }
    return textures;
}

static void init_struct_var(my_world_t *my_world)
{
    my_world->scale = (sfVector2i) {MAP_X, MAP_Y};
    my_world->pos = (sfVector2i) {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 4};
    my_world->pres_pos = (sfVector2i) {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 4};
    my_world->textures = get_textures();
    my_world->zoom = 0.3;
    my_world->tools = false;
    my_world->mode = true;
    my_world->tree = get_sprite();
    my_world->accuracy = DEF_MOUSE_ACC;
    my_world->angle.x = ANGLE_X;
    my_world->angle.y = ANGLE_Y;
    my_world->dog = get_dog();
}

my_world_t *get_my_world(void)
{
    int hash_tab[256];
    my_world_t *my_world = malloc(sizeof(my_world_t));

    hash_generate(hash_tab);
    if (!my_world)
        return NULL;
    init_struct_var(my_world);
    my_world->map = malloc(sizeof(int *) * (MAP_Y + 1));
    if (!my_world->map)
        return NULL;
    my_world->map[MAP_Y] = NULL;
    for (int y = 0; y < MAP_Y; y++) {
        my_world->map[y] = malloc(sizeof(int) * MAP_X);
        if (!my_world->map[y])
            return NULL;
        for (int x = 0; x < MAP_X; x++)
            my_world->map[y][x] = perlin_revenge(x, y, hash_tab);
    }
    smooth_map(my_world);
    return my_world;
}

void my_world_destroy(my_world_t *my_world)
{
    for (int i = 0; my_world->map[i]; i++)
        free(my_world->map[i]);
    free(my_world->map);
    dog_destroy(my_world->dog);
    distroy(my_world->tree.list);
    sfTexture_destroy(my_world->tree.texture_jaaj);
    sfSprite_destroy(my_world->tree.sprite_jaaj);
    sfTexture_destroy(my_world->tree.texture_fish);
    sfSprite_destroy(my_world->tree.sprite_fish);
    sfTexture_destroy(my_world->tree.texture);
    sfSprite_destroy(my_world->tree.sprite);
    sfTexture_destroy(my_world->tree.texture_kelp);
    sfSprite_destroy(my_world->tree.sprite_kelp);
    sfTexture_destroy((sfTexture *) my_world->textures.grass.texture);
    sfTexture_destroy((sfTexture *) my_world->textures.dirt.texture);
    sfTexture_destroy((sfTexture *) my_world->textures.stone.texture);
    sfTexture_destroy((sfTexture *) my_world->textures.snow.texture);
    sfTexture_destroy((sfTexture *) my_world->textures.water.texture);
    sfTexture_destroy((sfTexture *) my_world->textures.sand.texture);
    free(my_world);
}