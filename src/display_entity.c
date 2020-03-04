/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

void display_player(assets_t *assets, sfVector2f **map, my_world_t *my_world)
{
    sfVector2f pos;

    while (!(my_world->tree.list->pos.y < my_world->scale.y - 1))
        my_world->tree.list->pos.y--;
    while (!(my_world->tree.list->pos.x < my_world->scale.x - 1))
        my_world->tree.list->pos.x--;
    pos = map[my_world->tree.list->pos.y][my_world->tree.list->pos.x];
    pos.x -= my_world->zoom * DISPLAY_X * 0.5;
    pos.y -= my_world->zoom * DISPLAY_Y;
    sfSprite_setScale(my_world->tree.sprite_jaaj,
        (sfVector2f) {my_world->zoom / 2, my_world->zoom / 2});
    sfSprite_setPosition(my_world->tree.sprite_jaaj, pos);
    sfRenderWindow_drawSprite(assets->window, my_world->tree.sprite_jaaj, NULL);
}

static void display_select(assets_t *assets, sfVector2i pos_map,
    my_world_t *my_world, sfVector2f pos)
{
    if (my_world->map[pos_map.y][pos_map.x] > WATER_LEVEL) {
        sfSprite_setScale(my_world->tree.sprite,
            (sfVector2f) {my_world->zoom, my_world->zoom});
        sfSprite_setPosition(my_world->tree.sprite, pos);
        sfRenderWindow_drawSprite(assets->window, my_world->tree.sprite, NULL);
    }
    else {
        sfSprite_setScale(my_world->tree.sprite_kelp,
            (sfVector2f) {my_world->zoom, my_world->zoom});
        sfSprite_setPosition(my_world->tree.sprite_kelp, pos);
        sfRenderWindow_drawSprite(assets->window, my_world->tree.sprite_kelp,
            NULL);
    }
}

void display_something(assets_t *assets, sfVector2f **map, my_world_t *my_world)
{
    sfVector2f pos;
    list_t *end = my_world->tree.list->next;

    while (end) {
        if (end->pos.y < my_world->scale.y - 1 &&
            end->pos.x < my_world->scale.x - 1) {
            pos = map[end->pos.y][end->pos.x];
            pos.x -= my_world->zoom * DISPLAY_X * 0.5;
            pos.y -= my_world->zoom * DISPLAY_Y;
            display_select(assets, end->pos, my_world, pos);
        }
        end = end->next;
    }
    display_player(assets, map, my_world);
}