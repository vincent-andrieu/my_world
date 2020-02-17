/*
** EPITECH PROJECT, 2019
** fill_background
** File description:
** fill the window background
*/

#include "graph.h"

void fill_background(framebuffer_t *framebuffer, sfColor color)
{
    for (int y = 0; y < WINDOW_HEIGHT; y++)
        for (int x = 0; x < WINDOW_WIDTH; x++)
            my_put_pixel(framebuffer, x, y, color);
}