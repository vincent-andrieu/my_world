/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** manage textures
*/

#include "my_world.h"

sfVertexArray *display_texture(sfVector2f *point1, sfVector2f *point2,
    sfVector2f *point3)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfWhite};
    sfVertex vertex2 = {.position = *point2, .color = sfWhite};
    sfVertex vertex3 = {.position = *point3, .color = sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_setPrimitiveType(vertex_array , sfTriangleStrip);
    return vertex_array;
}

sfRenderStates *get_map_texture(int level, textures_t *textures)
{
    if (level < DIRT_LEVEL)
        return &textures->water;
    if (level < GRASS_LEVEL)
        return &textures->dirt;
    if (level < STONE_LEVEL)
        return &textures->grass;
    if (level < SNOW_LEVEL)
        return &textures->stone;
    return &textures->snow;
}