/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

static void exit_button(button_manage_t *button, assets_t *assets)
{
    if (button_ispressed(button->exit) && button->exit->is_activate) {
        button->exit->is_activate = false;
        while (sfSound_getStatus(button->exit->sound.sound) == sfPlaying);
        sfRenderWindow_close(assets->window);
    }
}

static void zoom(my_world_t *my_world, button_manage_t *button)
{
    if (button_ispressed(button->zoom_in) && button->zoom_in->is_activate) {
        my_world->zoom += ZOOM_EFFECT;
        button->zoom_in->is_activate = false;
    }
    if (button_ispressed(button->zoom_out) && my_world->zoom - ZOOM_EFFECT > 0
    && button->zoom_out->is_activate) {
        button->zoom_out->is_activate = false;
        my_world->zoom -= ZOOM_EFFECT;
    }
}

static void reset(my_world_t *my_world, button_manage_t *button)
{
    if (button_ispressed(button->restart) && button->restart->is_activate) {
        reset_map(my_world);
        button->restart->is_activate = false;
    }
    if (button_ispressed(button->tree) && button->tree->is_activate) {
        if (my_world->tree.select)
            my_world->tree.select = false;
        else
            my_world->tree.select = true;
        button->tree->is_activate = false;
    }
}

static void move(my_world_t *my_world, button_manage_t *button)
{
    if (button_ispressed(button->up) && button->up->is_activate) {
        my_world->pos.y = my_world->pos.y - MOVE_SPEED;
        button->up->is_activate = false;
    }
    if (button_ispressed(button->down) && button->down->is_activate) {
        my_world->pos.y = my_world->pos.y + MOVE_SPEED;
        button->down->is_activate = false;
    }
    if (button_ispressed(button->left) && button->left->is_activate) {
        my_world->pos.x = my_world->pos.x - MOVE_SPEED;
        button->left->is_activate = false;
    }
    if (button_ispressed(button->right) && button->right->is_activate) {
        my_world->pos.x = my_world->pos.x + MOVE_SPEED;
        button->right->is_activate = false;
    }
}

int button_effect(my_world_t **my_world, button_manage_t *button,
    assets_t *assets)
{
    map_angle_gest(*my_world, button);
    exit_button(button, assets);
    zoom(*my_world, button);
    resize(*my_world, button);
    reset(*my_world, button);
    move(*my_world, button);
    tools_select(*my_world, button);
    if (button_load(my_world, button) == EXIT_ERROR)
        return EXIT_ERROR;
    if (button_save(*my_world, button) == EXIT_ERROR)
        return EXIT_ERROR;
    refresh_screen(assets);
    sfRenderWindow_clear(assets->window, sfBlack);
    return EXIT_SUCCESS;
}