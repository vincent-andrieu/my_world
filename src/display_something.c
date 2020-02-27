/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

my_sprite_s get_sprite(void)
{
    my_sprite_s my_struct = {0};

    my_struct.sprite = sfSprite_create();
    my_struct.texture = sfTexture_createFromFile("./ressources/tree.png", NULL);
    sfSprite_setTexture(my_struct.sprite, my_struct.texture, sfTrue);
    sfSprite_setPosition(my_struct.sprite, (sfVector2f) {900, 500});
    return my_struct;
}

void display_something(assets_t *assets, sfVector2f **map, my_world_t *my_world)
{
    sfVector2f pos = map[my_world->tree.pos.y][my_world->tree.pos.x];

    pos.x -= my_world->zoom * DISPLAY_X * 0.5;
    pos.y -= my_world->zoom * DISPLAY_Y;
    sfSprite_setScale(my_world->tree.sprite,
        (sfVector2f) {my_world->zoom, my_world->zoom});
    sfSprite_setPosition(my_world->tree.sprite, pos);
    sfRenderWindow_drawSprite(assets->window, my_world->tree.sprite, NULL);
}