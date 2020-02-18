/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** edit map with the mouse
*/

#include "my_world.h"

static void travel_map(sfVector2i mouse,
                        my_world_t *my_world, sfVector2f **coords_map, bool up)
{
    for (int y = 0; y < my_world->scale.y; y++)
        for (int x = 0; x < my_world->scale.x; x++)
            if (coords_map[y][x].x - mouse.x > -MOUSE_ACC
            && coords_map[y][x].x - mouse.x < MOUSE_ACC
            && coords_map[y][x].y - mouse.y > -MOUSE_ACC
            && coords_map[y][x].y - mouse.y < MOUSE_ACC)
                my_world->map[y][x] += up ? EDIT_SPEED : -EDIT_SPEED;
}

void edit_map(sfRenderWindow *window,
            my_world_t *my_world, sfVector2f **coords_map)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        travel_map(sfMouse_getPositionRenderWindow(window),
            my_world, coords_map, true);
    else if (sfMouse_isButtonPressed(sfMouseRight))
        travel_map(sfMouse_getPositionRenderWindow(window),
            my_world, coords_map, false);
}

void reset_map(my_world_t *my_world)
{
    for (int y = 0; y < my_world->scale.y; y++)
        for (int x = 0; x < my_world->scale.x; x++)
            my_world->map[y][x] = 0;
}