/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"
#include <math.h>

static cube_t get_entity(void)
{
    cube_t my_cube = {0};

    my_cube.a = (sfVector3i) {0, 0, 0};
    my_cube.b = (sfVector3i) {DISPLAY_X, 0, 0};
    my_cube.c = (sfVector3i) {DISPLAY_X, DISPLAY_Y, 0};
    my_cube.d = (sfVector3i) {0, DISPLAY_Y, 0};
    my_cube.e = (sfVector3i) {0, 0, 32};
    my_cube.f = (sfVector3i) {DISPLAY_X, 0, 32};
    my_cube.g = (sfVector3i) {0, DISPLAY_Y, 32};
    my_cube.h = (sfVector3i) {DISPLAY_X, DISPLAY_Y, 32};
    return my_cube;
}

static proj_cube_t get_cube_iso(cube_t cube, my_world_t *my_world)
{
    proj_cube_t my_cube = {0};

    my_cube.a = project_cube(cube.a, my_world, my_world->pos, my_world->zoom);
    my_cube.b = project_cube(cube.b, my_world, my_world->pos, my_world->zoom);
    my_cube.c = project_cube(cube.c, my_world, my_world->pos, my_world->zoom);
    my_cube.d = project_cube(cube.d, my_world, my_world->pos, my_world->zoom);
    my_cube.e = project_cube(cube.e, my_world, my_world->pos, my_world->zoom);
    my_cube.f = project_cube(cube.f, my_world, my_world->pos, my_world->zoom);
    my_cube.g = project_cube(cube.g, my_world, my_world->pos, my_world->zoom);
    my_cube.h = project_cube(cube.h, my_world, my_world->pos, my_world->zoom);
    return my_cube;
}

static void draw_seg(assets_t *assets, sfVector2f one, sfVector2f two,
    sfColor color)
{
    sfVertexArray *line = create_edge(&one, &two, color);

    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);
}

static void print_cube(assets_t *assets, proj_cube_t cube)
{
    draw_seg(assets, cube.a, cube.b, sfWhite);
    draw_seg(assets, cube.b, cube.c, sfWhite);
    draw_seg(assets, cube.c, cube.d, sfWhite);
    draw_seg(assets, cube.d, cube.a, sfWhite);
    draw_seg(assets, cube.h, cube.g, sfWhite);
    draw_seg(assets, cube.g, cube.e, sfWhite);
    draw_seg(assets, cube.e, cube.f, sfWhite);
    draw_seg(assets, cube.f, cube.h, sfWhite);
    draw_seg(assets, cube.a, cube.e, sfWhite);
    draw_seg(assets, cube.b, cube.f, sfWhite);
    draw_seg(assets, cube.c, cube.h, sfWhite);
    draw_seg(assets, cube.d, cube.g, sfWhite);
}

void display_my_entity(assets_t *assets, my_world_t *my_world)
{
    proj_cube_t cube = get_cube_iso(get_entity(), my_world);

    print_cube(assets, cube);
    if (cos(my_world->angle.x) > 0)
        display_face_one(cube, assets, my_world);
    else
        display_face_two(cube, assets, my_world);
    display_end(cube, assets, my_world);
}