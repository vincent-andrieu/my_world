/*
** EPITECH PROJECT, 2019
** framebuffer_create
** File description:
** create a framebuffer
*/

#include <stdlib.h>
#include "graph.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));

    if (framebuffer == NULL)
        return NULL;
    framebuffer->pixels = malloc((sizeof(sfUint8)) * (width * height) * 4);
    if (framebuffer->pixels == NULL)
        return NULL;
    for (unsigned int i = 0; i < (width * height) * 4; i++)
        framebuffer->pixels[i] = 0;
    framebuffer->width = width;
    framebuffer->height = height;
    return framebuffer;
}