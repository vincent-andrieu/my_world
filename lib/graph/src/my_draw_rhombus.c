/*
** EPITECH PROJECT, 2019
** my_draw_rhombus
** File description:
** draw a rhombus
*/

#include <SFML/Graphics.h>
#include "graph.h"

void my_draw_rhombus(framebuffer_t *framebuffer, sfVector2f coord,
                    int radius, sfColor color)
{
    int n = radius;

    for (int width = radius % 2; width <= radius; width++, n--)
        for (int x = coord.x - width; x <= coord.x + width; x++) {
            my_put_pixel(framebuffer, x, coord.y - n, color);
            my_put_pixel(framebuffer, x, coord.y + n, color);
        }
}