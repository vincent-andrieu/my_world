/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

static void my_combinated(sfEvent event, my_world_t *my_world)
{
    if (event.key.control && event.key.code == sfKeyS)
        button_save(my_world, NULL, true);
    if (event.key.control && event.key.code == sfKeyR)
        reset_map(my_world);
    if (event.key.control && event.key.code == sfKeyUp)
        my_world->angle.y -= SPEED_ANGLE;
    if (event.key.control && event.key.code == sfKeyDown)
        my_world->angle.y += SPEED_ANGLE;
    if (event.key.control && event.key.code == sfKeyLeft)
        my_world->angle.x -= SPEED_ANGLE;
    if (event.key.control && event.key.code == sfKeyRight)
        my_world->angle.x += SPEED_ANGLE;
}

void event_set(sfEvent evt, my_world_t *wrd, assets_t *assets)
{
    if (!evt.key.control && evt.key.code == sfKeyUp)
        wrd->pos.y = wrd->pos.y - MOVE_SPEED;
    if (!evt.key.control && evt.key.code == sfKeyDown)
        wrd->pos.y = wrd->pos.y + MOVE_SPEED;
    if (!evt.key.control && evt.key.code == sfKeyLeft)
        wrd->pos.x = wrd->pos.x - MOVE_SPEED;
    if (!evt.key.control && evt.key.code == sfKeyRight)
        wrd->pos.x = wrd->pos.x + MOVE_SPEED;
    if (!evt.key.control && evt.key.code == sfKeyZ && wrd->tree.list->pos.x > 0)
        wrd->tree.list->pos.x--;
    if (!evt.key.control && evt.key.code == sfKeyS &&
    wrd->tree.list->pos.x < wrd->scale.x)
        wrd->tree.list->pos.x++;
    if (!evt.key.control && evt.key.code == sfKeyQ &&
    wrd->tree.list->pos.y < wrd->scale.y)
        wrd->tree.list->pos.y++;
    if (!evt.key.control && evt.key.code == sfKeyD && wrd->tree.list->pos.y > 0)
        wrd->tree.list->pos.y--;
    my_precision(wrd, assets);
    my_combinated(evt, wrd);
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