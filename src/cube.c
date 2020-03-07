/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include <math.h>
#include "my_world.h"

static cube_t get_cube(void)
{
    cube_t my_cube = {0};

    my_cube.a = (sfVector3i) {0, 0, 0};
    my_cube.b = (sfVector3i) {100, 0, 0};
    my_cube.c = (sfVector3i) {100, 100, 0};
    my_cube.d = (sfVector3i) {0, 100, 0};
    my_cube.e = (sfVector3i) {0, 0, 100};
    my_cube.f = (sfVector3i) {100, 0, 100};
    my_cube.g = (sfVector3i) {0, 100, 100};
    my_cube.h = (sfVector3i) {100, 100, 100};
    return my_cube;
}

sfVector2f project_cube(sfVector3i coord, my_world_t *my_world,
    sfVector2i pos, float zoom)
{
    sfVector2f my_2d_vector = {0};

    my_2d_vector.x = cos(my_world->angle.x) * (coord.x * zoom) -
    cos(my_world->angle.x) * (coord.y * zoom) + pos.x;
    my_2d_vector.y = sin(my_world->angle.y) * (coord.y * zoom) +
    sin(my_world->angle.y) * (coord.x * zoom) - (coord.z * zoom) + pos.y;
    return my_2d_vector;
}

static proj_cube_t get_axes_iso(cube_t cube, my_world_t *world)
{
    proj_cube_t my_cube = {0};

    my_cube.a = project_cube(cube.a, world, (sfVector2i) {X_AXES, Y_AXES}, 1);
    my_cube.b = project_cube(cube.b, world, (sfVector2i) {X_AXES, Y_AXES}, 1);
    my_cube.c = project_cube(cube.c, world, (sfVector2i) {X_AXES, Y_AXES}, 1);
    my_cube.d = project_cube(cube.d, world, (sfVector2i) {X_AXES, Y_AXES}, 1);
    my_cube.e = project_cube(cube.e, world, (sfVector2i) {X_AXES, Y_AXES}, 1);
    my_cube.f = project_cube(cube.f, world, (sfVector2i) {X_AXES, Y_AXES}, 1);
    my_cube.g = project_cube(cube.g, world, (sfVector2i) {X_AXES, Y_AXES}, 1);
    my_cube.h = project_cube(cube.h, world, (sfVector2i) {X_AXES, Y_AXES}, 1);
    return my_cube;
}

sfVertexArray *create_edge(sfVector2f *point1, sfVector2f *point2,
    sfColor color)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = color};
    sfVertex vertex2 = {.position = *point2, .color = color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array , sfLinesStrip);
    return vertex_array;
}

void display_my_cube(assets_t *assets, my_world_t *my_world)
{
    cube_t cube_coord = get_cube();
    proj_cube_t cube = get_axes_iso(cube_coord, my_world);
    sfVertexArray *line;

    line = create_edge(&cube.a, &cube.b, sfRed);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);
    line = create_edge(&cube.d, &cube.a, sfGreen);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);
    line = create_edge(&cube.a, &cube.e, sfBlue);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);
}