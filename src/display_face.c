/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include <math.h>
#include "my_world.h"

void display_end(proj_cube_t cube, assets_t *tool, my_world_t *easy)
{
    sfVertexArray *li;

    if (sin(easy->angle.y) > 0) {
        li = display_texture(&cube.h, &cube.f, &cube.e);
        sfRenderWindow_drawVertexArray(tool->window, li, &easy->textures.grass);
        sfVertexArray_destroy(li);
        li = display_texture(&cube.h, &cube.g, &cube.e);
        sfRenderWindow_drawVertexArray(tool->window, li, &easy->textures.grass);
        sfVertexArray_destroy(li);
    }
    else {
        li = display_texture(&cube.a, &cube.b, &cube.c);
        sfRenderWindow_drawVertexArray(tool->window, li, &easy->textures.water);
        sfVertexArray_destroy(li);
        li = display_texture(&cube.a, &cube.d, &cube.c);
        sfRenderWindow_drawVertexArray(tool->window, li, &easy->textures.water);
        sfVertexArray_destroy(li);
    }
}

void display_face_one(proj_cube_t cube, assets_t *tools, my_world_t *world)
{
    sfVertexArray *line;

    line = display_texture(&cube.b, &cube.f, &cube.c);
    sfRenderWindow_drawVertexArray(tools->window, line, &world->textures.snow);
    sfVertexArray_destroy(line);
    line = display_texture(&cube.c, &cube.f, &cube.h);
    sfRenderWindow_drawVertexArray(tools->window, line, &world->textures.snow);
    sfVertexArray_destroy(line);
    line = display_texture(&cube.c, &cube.h, &cube.d);
    sfRenderWindow_drawVertexArray(tools->window, line, &world->textures.stone);
    sfVertexArray_destroy(line);
    line = display_texture(&cube.h, &cube.g, &cube.d);
    sfRenderWindow_drawVertexArray(tools->window, line, &world->textures.stone);
    sfVertexArray_destroy(line);
}

void display_face_two(proj_cube_t cube, assets_t *assets, my_world_t *world)
{
    sfVertexArray *line;

    line = display_texture(&cube.d, &cube.g, &cube.h);
    sfRenderWindow_drawVertexArray(assets->window, line, &world->textures.dirt);
    sfVertexArray_destroy(line);
    line = display_texture(&cube.d, &cube.h, &cube.c);
    sfRenderWindow_drawVertexArray(assets->window, line, &world->textures.dirt);
    sfVertexArray_destroy(line);
    line = display_texture(&cube.f, &cube.c, &cube.b);
    sfRenderWindow_drawVertexArray(assets->window, line, &world->textures.sand);
    sfVertexArray_destroy(line);
    line = display_texture(&cube.f, &cube.c, &cube.h);
    sfRenderWindow_drawVertexArray(assets->window, line, &world->textures.sand);
    sfVertexArray_destroy(line);
}