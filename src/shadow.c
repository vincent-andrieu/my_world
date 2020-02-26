/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

sfVertexArray *shadow(sfVector2f *point1, sfVector2f *point2,
    sfVector2f *point3, sfColor color)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = color};
    sfVertex vertex2 = {.position = *point2, .color = color};
    sfVertex vertex3 = {.position = *point3, .color = color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_setPrimitiveType(vertex_array , sfTriangleStrip);
    return vertex_array;
}

sfColor get_color(int point1, int point2, int point3, int point4)
{
    sfColor color;
    int tmp = (point2 - point4) / 2;
    int tmp2 = (point1 - point3) / 2;

    if (tmp < tmp2)
        tmp = tmp2;
    if (tmp > 200)
        tmp = 200;
    else if (tmp < 0)
        tmp = 0;
    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = tmp;
    return color;
}