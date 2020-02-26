/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** manage textures
*/

#include "my_world.h"

static sfVertexArray *display_texture(sfVector2f *point1, sfVector2f *point2,
    sfVector2f *point3)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfWhite};
    sfVertex vertex2 = {.position = *point2, .color = sfWhite};
    sfVertex vertex3 = {.position = *point3, .color = sfWhite};

    vertex1.texCoords = (sfVector2f) {0, 0};
    vertex2.texCoords = (sfVector2f) {32, 0};
    vertex3.texCoords = (sfVector2f) {0, 32};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_setPrimitiveType(vertex_array , sfTriangleStrip);
    return vertex_array;
}

static void shadow_manage(my_world_t *world, sfVector2f **map,
                    sfVector2i pos, sfRenderWindow *window)
{
    sfColor color = get_color(world->map[pos.y][pos.x + 1],
        world->map[pos.y][pos.x], world->map[pos.y + 1][pos.x],
        world->map[pos.y + 1][pos.x + 1]);
    sfVertexArray *line;

    line = shadow(&map[pos.y][pos.x], &map[pos.y + 1][pos.x],
        &map[pos.y][pos.x + 1], color);
    sfRenderWindow_drawVertexArray(window, line, NULL);
    sfVertexArray_destroy(line);
    line = shadow(&map[pos.y + 1][pos.x + 1], &map[pos.y + 1][pos.x],
        &map[pos.y][pos.x + 1], color);
    sfRenderWindow_drawVertexArray(window, line, NULL);
    sfVertexArray_destroy(line);
}

void calc_textures(my_world_t *world, sfVector2f **map,
                    sfVector2i pos, sfRenderWindow *window)
{
    sfVertexArray *line;

    if (pos.y < world->scale.y - 1 && pos.x < world->scale.x - 1) {
        line = display_texture(&map[pos.y][pos.x], &map[pos.y + 1][pos.x],
            &map[pos.y][pos.x + 1]);
        sfRenderWindow_drawVertexArray(window, line,
            get_map_texture(world->map[pos.y][pos.x], &world->textures));
        sfVertexArray_destroy(line);
        line = display_texture(&map[pos.y + 1][pos.x + 1],
            &map[pos.y + 1][pos.x], &map[pos.y][pos.x + 1]);
        sfRenderWindow_drawVertexArray(window, line,
            get_map_texture(world->map[pos.y][pos.x], &world->textures));
        sfVertexArray_destroy(line);
        shadow_manage(world, map, pos, window);
    }
}

sfRenderStates *get_map_texture(int level, textures_t *textures)
{
    if (level < DIRT_LEVEL)
        return &textures->sand;
    if (level < GRASS_LEVEL)
        return &textures->dirt;
    if (level < STONE_LEVEL)
        return &textures->grass;
    if (level < SNOW_LEVEL)
        return &textures->stone;
    return &textures->snow;
}

void water_textures(my_world_t *my_world, sfVector2f **map,
                    sfVector2i coord, sfRenderWindow *window)
{
    sfVertexArray *line;

    if (coord.y < my_world->scale.y - 1 && coord.x < my_world->scale.x - 1) {
        line = display_texture(&map[coord.y][coord.x],
            &map[coord.y + 1][coord.x], &map[coord.y][coord.x + 1]);
        sfRenderWindow_drawVertexArray(window, line, &my_world->textures.water);
        sfVertexArray_destroy(line);
        line = display_texture(&map[coord.y + 1][coord.x + 1],
            &map[coord.y + 1][coord.x], &map[coord.y][coord.x + 1]);
        sfRenderWindow_drawVertexArray(window, line, &my_world->textures.water);
        sfVertexArray_destroy(line);
    }
}