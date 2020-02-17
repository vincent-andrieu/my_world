/*
** EPITECH PROJECT, 2019
** my_get_pixel_color
** File description:
** get a pixel color
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "graph.h"

sfColor my_get_pixel_color(framebuffer_t *framebuffer, unsigned int x,
                            unsigned int y)
{
    if (x <= framebuffer->width && y <= framebuffer->height)
        return (sfColor) {
            framebuffer->pixels[framebuffer->width * 4 * y + x * 4 + 0],
            framebuffer->pixels[framebuffer->width * 4 * y + x * 4 + 1],
            framebuffer->pixels[framebuffer->width * 4 * y + x * 4 + 2],
            framebuffer->pixels[framebuffer->width * 4 * y + x * 4 + 3]
        };
    return (sfColor) {0, 0, 0, 0};
}