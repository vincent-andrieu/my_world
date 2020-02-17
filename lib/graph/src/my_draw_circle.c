/*
** EPITECH PROJECT, 2019
** my_draw_circle
** File description:
** draw a circle
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "graph.h"

void my_draw_circle(framebuffer_t *framebuffer, sfVector2f coord,
                    int radius, sfColor color)
{
    float x;
    float y;

    for (float angle = 0; angle < 90; angle += 0.1) {
        x = radius * cos(angle * M_PI / 180);
        y = radius * sin(angle * M_PI / 180);
        my_draw_line(framebuffer, (sfVector2f) {coord.x + x, coord.y + y},
                    (sfVector2f) {coord.x + x, coord.y}, color);
        my_draw_line(framebuffer, (sfVector2f) {coord.x - x, coord.y - y},
                    (sfVector2f) {coord.x - x, coord.y}, color);
        my_draw_line(framebuffer, (sfVector2f) {coord.x - x, coord.y + y},
                    (sfVector2f) {coord.x - x, coord.y}, color);
        my_draw_line(framebuffer, (sfVector2f) {coord.x + x, coord.y - y},
                    (sfVector2f) {coord.x + x, coord.y}, color);
    }
}