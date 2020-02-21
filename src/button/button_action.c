/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

#define ZOOM_EFFECT 0.1

static void exit_button(button_manage_t *button, assets_t *assets)
{
    if (button_ispressed(button->exit))
        sfRenderWindow_close(assets->window);
}

static void zoom(my_world_t *my_world, button_manage_t *button)
{
    if (button_ispressed(button->zoom_in))
        my_world->zoom += ZOOM_EFFECT;
    if (button_ispressed(button->zoom_out) && my_world->zoom - ZOOM_EFFECT > 0)
        my_world->zoom -= ZOOM_EFFECT;
}

static void resize(my_world_t *my_world, button_manage_t *button)
{
    if (button_ispressed(button->size_y_min) && my_world->scale.y > 2)
        get_resize_map(my_world, 0, -1);
    if (button_ispressed(button->size_y_plus))
        get_resize_map(my_world, 0, 1);
    if (button_ispressed(button->size_x_min) && my_world->scale.x > 2)
        get_resize_map(my_world, -1, 0);
    if (button_ispressed(button->size_x_plus))
        get_resize_map(my_world, 1, 0);
}

static void reset(my_world_t *my_world, button_manage_t *button)
{
    if (button_ispressed(button->restart))
        reset_map(my_world);
}

static void move(my_world_t *my_world, button_manage_t *button)
{
    if (button_ispressed(button->up))
        my_world->pos.y = my_world->pos.y - MOVE_SPEED;
    if (button_ispressed(button->down))
        my_world->pos.y = my_world->pos.y + MOVE_SPEED;
    if (button_ispressed(button->left))
        my_world->pos.x = my_world->pos.x - MOVE_SPEED;
    if (button_ispressed(button->right))
        my_world->pos.x = my_world->pos.x + MOVE_SPEED;
}

void button_effect(my_world_t *my_world, button_manage_t *button,
    assets_t *assets)
{
    exit_button(button, assets);
    zoom(my_world, button);
    resize(my_world, button);
    reset(my_world, button);
    move(my_world, button);
}