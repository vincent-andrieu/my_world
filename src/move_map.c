/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

void map_angle_gest(my_world_t *my_world, button_manage_t *button)
{
    if (button_ispressed(button->angle_y_min)
    && button->angle_y_min->is_activate) {
        my_world->angle.y = my_world->angle.y - SPEED_ANGLE;
        button->angle_y_min->is_activate = false;
    }
    if (button_ispressed(button->angle_y_plus)
    && button->angle_y_plus->is_activate) {
        my_world->angle.y = my_world->angle.y + SPEED_ANGLE;
        button->angle_y_plus->is_activate = false;
    }
    if (button_ispressed(button->angle_x_min)
    && button->angle_x_min->is_activate) {
        my_world->angle.x = my_world->angle.x - SPEED_ANGLE;
        button->angle_x_min->is_activate = false;
    }
    if (button_ispressed(button->angle_x_plus)
    && button->angle_x_plus->is_activate) {
        my_world->angle.x = my_world->angle.x + SPEED_ANGLE;
        button->angle_x_plus->is_activate = false;
    }
}