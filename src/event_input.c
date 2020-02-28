/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

void event_set(sfEvent event, my_world_t *world)
{
    if (event.key.code == sfKeyUp)
        world->pos.y = world->pos.y - MOVE_SPEED;
    if (event.key.code == sfKeyDown)
        world->pos.y = world->pos.y + MOVE_SPEED;
    if (event.key.code == sfKeyLeft)
        world->pos.x = world->pos.x - MOVE_SPEED;
    if (event.key.code == sfKeyRight)
        world->pos.x = world->pos.x + MOVE_SPEED;
    if (event.key.code == sfKeyR)
        reset_map(world);
    if (event.key.code == sfKeyZ && world->tree.list->pos.x > 0)
        world->tree.list->pos.x--;
    if (event.key.code == sfKeyS && world->tree.list->pos.x < world->scale.x)
        world->tree.list->pos.x++;
    if (event.key.code == sfKeyQ && world->tree.list->pos.y < world->scale.y)
        world->tree.list->pos.y++;
    if (event.key.code == sfKeyD && world->tree.list->pos.y > 0)
        world->tree.list->pos.y--;
}