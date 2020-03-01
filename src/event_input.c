/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

void event_set(sfEvent event, my_world_t *world, assets_t *assets)
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
    my_precision(world, assets);
}

void display_precision(float accuracy, assets_t *assets)
{
    for (unsigned int i = 0;
    i < assets->framebuffer->width * assets->framebuffer->height * 4; i++)
        assets->framebuffer->pixels[i] = 0;
    my_draw_line(assets->framebuffer, (sfVector2f) {acc_pos_from.x,
        acc_pos_from.y},(sfVector2f) {acc_pos_to.x, acc_pos_to.y}, PREC_COLOR);
    my_draw_circle(assets->framebuffer, (sfVector2f)
        {acc_pos_from.x + accuracy, acc_pos_from.y}, 5, PREC_COLOR);
    sfTexture_updateFromPixels(assets->texture, assets->framebuffer->pixels,
                                WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
}

void my_precision(my_world_t *my_world, assets_t *assets)
{
    sfVector2i coord = sfMouse_getPositionRenderWindow(assets->window);

    if (ABS(acc_pos_from.x - coord.x) < 30 && ABS(acc_pos_from.y - coord.y) < 30
    && coord.x > acc_pos_from.x && coord.x < acc_pos_to.x)
        my_world->accuracy = (coord.x - acc_pos_from.x);
    display_precision(my_world->accuracy, assets);
}