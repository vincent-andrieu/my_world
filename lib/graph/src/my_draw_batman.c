/*
** EPITECH PROJECT, 2019
** my_draw_batman
** File description:
** draw a batman
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "graph.h"

void my_draw_batman(framebuffer_t *fb, vec co, int radius, sfColor c)
{
    float x;
    float y;

    for (float angle = 0; angle < 45; angle += 0.1) {
        x = radius * cos(angle * M_PI / 180);
        y = radius * sin(angle * M_PI / 180);
        my_draw_line(fb, (vec) {co.x + x, co.y + y}, (vec) {co.x + x, co.y}, c);
        my_draw_line(fb, (vec) {co.x - x, co.y - y}, (vec) {co.x - x, co.y}, c);
        my_draw_line(fb, (vec) {co.x - x, co.y + y}, (vec) {co.x - x, co.y}, c);
        my_draw_line(fb, (vec) {co.x + x, co.y - y}, (vec) {co.x + x, co.y}, c);
        my_draw_line(fb, (vec) {co.x + x, co.y + y}, (vec) {co.x, co.y - y}, c);
        my_draw_line(fb, (vec) {co.x - x, co.y - y}, (vec) {co.x, co.y + y}, c);
        my_draw_line(fb, (vec) {co.x + x, co.y - y}, (vec) {co.x, co.y + y}, c);
        my_draw_line(fb, (vec) {co.x - x, co.y + y}, (vec) {co.x, co.y - y}, c);
    }
}