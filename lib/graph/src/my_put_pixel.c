/*
** EPITECH PROJECT, 2019
** my_put_pixel
** File description:
** put a pixel
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graph.h"

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
                    sfColor color)
{
    if (x <= framebuffer->width && y <= framebuffer->height) {
        framebuffer->pixels[framebuffer->width * 4 * y + x * 4 + 0] = color.r;
        framebuffer->pixels[framebuffer->width * 4 * y + x * 4 + 1] = color.g;
        framebuffer->pixels[framebuffer->width * 4 * y + x * 4 + 2] = color.b;
        framebuffer->pixels[framebuffer->width * 4 * y + x * 4 + 3] = color.a;
    }
}