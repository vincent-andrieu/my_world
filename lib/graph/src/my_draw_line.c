/*
** EPITECH PROJECT, 2019
** my_draw_line
** File description:
** draw a line
*/

#include <SFML/Graphics.h>
#include "graph.h"

static void swap_float(float *a, float *b)
{
    float c = *a;

    *a = *b;
    *b = c;
}

void my_draw_line(framebuffer_t *framebuffer, sfVector2f point_a,
                    sfVector2f point_b, sfColor color)
{
    float dx;
    float dy;
    sfVector2f coords_p;

    if (point_a.x > point_b.x) {
        swap_float(&point_a.x, &point_b.x);
        swap_float(&point_a.y, &point_b.y);
    }
    dx = point_b.x - point_a.x;
    dy = point_b.y - point_a.y;
    if (point_a.x == point_b.x)
        my_draw_rect(framebuffer, (sfVector2f) {point_a.x, point_a.y},
            (sfVector2f) {1, dy}, color);
    else
        for (float x = point_a.x; x < point_b.x; x++) {
            coords_p = (sfVector2f) {x, point_a.y + dy * (x - point_a.x) / dx};
            my_draw_rect(framebuffer, coords_p, (sfVector2f) {1,
                point_a.y == point_b.y ? 1 : (point_a.y + dy
                * (x + 1 - point_a.x) / dx) - coords_p.y}, color);
        }
}