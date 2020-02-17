/*
** EPITECH PROJECT, 2019
** my_put_rect
** File description:
** draw a rect
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graph.h"
#include <stdio.h>

void my_draw_rect(framebuffer_t *buffer, sfVector2f coords,
                    sfVector2f size, sfColor color)
{
    for (float i = 0; size.x > 0 ? i < size.x : i > size.x;
    i += size.x < 0 ? -1 : 1)
        for (float j = 0; size.y > 0 ? j < size.y : j > size.y;
        j += size.y < 0 ? -1 : 1)
            my_put_pixel(buffer, coords.x + i, coords.y + j, color);
}