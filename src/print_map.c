/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include <math.h>
#include "my.h"
#include "graph.h"
#include "my_world.h"

static sfVector2f project_iso_point(int x, int y, int z, sfVector2i pos)
{
    sfVector2f my_2d_vector = {0};

    my_2d_vector.x = cos(ANGLE_X) * x - cos(ANGLE_X) * y + pos.x;
    my_2d_vector.y = sin(ANGLE_Y) * y + sin(ANGLE_Y) * x - z + pos.y;
    return my_2d_vector;
}

sfVector2f **create_twod_map(int **three_d_map, my_world_t *my_world)
{
    sfVector2f **my_map = malloc(sizeof(sfVector2f *)
                                * (my_world->scale.y + 1));

    if (!my_map)
        return NULL;
    my_map[(int) my_world->scale.y] = NULL;
    for (int y = 0; y < my_world->scale.y; y++) {
        my_map[y] = malloc(sizeof(sfVector2f) * my_world->scale.x);
        if (!my_map[y])
            return NULL;
        for (int x = 0; x < my_world->scale.x; x++)
            my_map[y][x] = project_iso_point(x * DISPLAY_X * my_world->zoom,
                y * DISPLAY_Y * my_world->zoom,
                three_d_map[y][x] * my_world->zoom, my_world->pos);
    }
    return my_map;
}

static sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfBlack};
    sfVertex vertex2 = {.position = *point2, .color = sfBlack};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array , sfLinesStrip);
    return vertex_array;
}

void draw_twod_map(assets_t *assets, sfVector2f **map, my_world_t *my_world)
{
    sfVertexArray *line;

    for (int y = 0; y < my_world->scale.y; y++) {
        for (int x = 0; x < my_world->scale.x; x++) {
            calc_textures(my_world, map, (sfVector2i) {x, y}, assets->window);
            if (y < my_world->scale.y - 1) {
                line = create_line(&map[y][x], &map[y + 1][x]);
                sfRenderWindow_drawVertexArray(assets->window, line, NULL);
                sfVertexArray_destroy(line);
            }
            if (x < my_world->scale.x - 1) {
                line = create_line(&map[y][x], &map[y][x + 1]);
                sfRenderWindow_drawVertexArray(assets->window, line, NULL);
                sfVertexArray_destroy(line);
            }
        }
    }
    refresh_screen(assets);
    sfRenderWindow_clear(assets->window, sfBlack);
}