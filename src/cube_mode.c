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

void display_my_entity(assets_t *assets, my_world_t *my_world)
{
    cube_t cube_coord = get_entity();
    proj_cube_t cube = get_cube_iso(cube_coord, my_world);
    sfVertexArray *line;

    line = create_edge(&cube.a, &cube.b, sfWhite);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);
    line = create_edge(&cube.b, &cube.c, sfWhite);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);
    line = create_edge(&cube.c, &cube.d, sfWhite);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);
    line = create_edge(&cube.d, &cube.a, sfWhite);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);

    line = create_edge(&cube.h, &cube.g, sfWhite);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);
    line = create_edge(&cube.g, &cube.e, sfWhite);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);
    line = create_edge(&cube.e, &cube.f, sfWhite);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);
    line = create_edge(&cube.f, &cube.h, sfWhite);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);

    line = create_edge(&cube.a, &cube.e, sfBlue);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);
    line = create_edge(&cube.b, &cube.f, sfRed);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);
    line = create_edge(&cube.c, &cube.h, sfGreen);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);
    line = create_edge(&cube.d, &cube.g, sfMagenta);
    sfRenderWindow_drawVertexArray(assets->window, line, NULL);
    sfVertexArray_destroy(line);

    if (cos(my_world->angle.x) > 0) {
        line = display_texture(&cube.b, &cube.f, &cube.c);
        sfRenderWindow_drawVertexArray(assets->window, line, &my_world->textures.snow);
        sfVertexArray_destroy(line);
        line = display_texture(&cube.c, &cube.f, &cube.h);
        sfRenderWindow_drawVertexArray(assets->window, line, &my_world->textures.snow);
        sfVertexArray_destroy(line);
        line = display_texture(&cube.c, &cube.h, &cube.d);
        sfRenderWindow_drawVertexArray(assets->window, line, &my_world->textures.stone);
        sfVertexArray_destroy(line);
        line = display_texture(&cube.h, &cube.g, &cube.d);
        sfRenderWindow_drawVertexArray(assets->window, line, &my_world->textures.stone);
        sfVertexArray_destroy(line);
    }
    else {
        line = display_texture(&cube.d, &cube.g, &cube.h);
        sfRenderWindow_drawVertexArray(assets->window, line, &my_world->textures.dirt);
        sfVertexArray_destroy(line);
        line = display_texture(&cube.d, &cube.h, &cube.c);
        sfRenderWindow_drawVertexArray(assets->window, line, &my_world->textures.dirt);
        sfVertexArray_destroy(line);
        line = display_texture(&cube.f, &cube.c, &cube.b);
        sfRenderWindow_drawVertexArray(assets->window, line, &my_world->textures.sand);
        sfVertexArray_destroy(line);
        line = display_texture(&cube.f, &cube.c, &cube.h);
        sfRenderWindow_drawVertexArray(assets->window, line, &my_world->textures.sand);
        sfVertexArray_destroy(line);
    }
    if (sin(my_world->angle.y) > 0) {
        line = display_texture(&cube.h, &cube.f, &cube.e);
        sfRenderWindow_drawVertexArray(assets->window, line, &my_world->textures.grass);
        sfVertexArray_destroy(line);
        line = display_texture(&cube.h, &cube.g, &cube.e);
        sfRenderWindow_drawVertexArray(assets->window, line, &my_world->textures.grass);
        sfVertexArray_destroy(line);
    }
    else {
        line = display_texture(&cube.a, &cube.b, &cube.c);
        sfRenderWindow_drawVertexArray(assets->window, line, &my_world->textures.water);
        sfVertexArray_destroy(line);
        line = display_texture(&cube.a, &cube.d, &cube.c);
        sfRenderWindow_drawVertexArray(assets->window, line, &my_world->textures.water);
        sfVertexArray_destroy(line);
    }
}