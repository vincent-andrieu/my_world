/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include <SFML/Graphics.h>
#include "my_button.h"

float as_seconds(sfTime time)
{
    return (float)time.microseconds / 1000000.f;
}

void button_status(int temp, my_button_shape_t *my_button)
{
    if (as_seconds(sfClock_getElapsedTime(my_button->clock_start)) < TIME_BUT)
        return;
    if (my_button->is_pressed) {
        my_button->is_pressed = false;
        my_button->toggle = 2;
    }
    else
        my_button->toggle = temp;
    if (my_button->toggle == 2)
        my_button->is_activate = true;
    sfClock_restart(my_button->clock_start);
}