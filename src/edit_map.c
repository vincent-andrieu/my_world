/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** edit map with the mouse
*/

#include "my_world.h"

static bool tile_selec_pos(sfVector2i mouse, my_world_t *my_world,
    sfVector2f **coords_map, sfVector2i pos)
{
    int x = pos.x;
    int y = pos.y;

    if (y < my_world->scale.y - 1 && x < my_world->scale.x - 1)
        if (is_in_triangle(coords_map[y][x], coords_map[y + 1][x],
            coords_map[y][x + 1], (sfVector2f) {mouse.x, mouse.y}) ^
            is_in_triangle(coords_map[y + 1][x + 1], coords_map[y + 1][x],
                coords_map[y][x + 1], (sfVector2f) {mouse.x, mouse.y})) {
            my_world->map[y][x] += EDIT_SPEED;
            my_world->map[y][x + 1] += EDIT_SPEED;
            my_world->map[y + 1][x] += EDIT_SPEED;
            my_world->map[y + 1][x + 1] += EDIT_SPEED;
            return true;
        }
    return false;
}

static bool tile_selec_neg(sfVector2i mouse, my_world_t *my_world,
    sfVector2f **coords_map, sfVector2i pos)
{
    int x = pos.x;
    int y = pos.y;

    if (y < my_world->scale.y - 1 && x < my_world->scale.x - 1)
        if (is_in_triangle(coords_map[y][x], coords_map[y + 1][x],
        coords_map[y][x + 1], (sfVector2f) {mouse.x, mouse.y}) ^
        is_in_triangle(coords_map[y + 1][x + 1], coords_map[y + 1][x],
        coords_map[y][x + 1], (sfVector2f) {mouse.x, mouse.y})) {
            my_world->map[y][x] -= EDIT_SPEED;
            my_world->map[y][x + 1] -= EDIT_SPEED;
            my_world->map[y + 1][x] -= EDIT_SPEED;
            my_world->map[y + 1][x + 1] -= EDIT_SPEED;
            return true;
        }
    return false;
}

static void travel_map(sfVector2i pos,
                        my_world_t *world, sfVector2f **co_map, bool up)
{
    bool stat = false;

    for (int y = world->scale.y - 1; y >= 0; y--)
        for (int x = world->scale.x - 1; x >= 0; x--) {
            if (up && !world->tools)
                stat = tile_selec_pos(pos, world, co_map, (sfVector2i) {x, y});
            else if (!world->tools)
                stat = tile_selec_neg(pos, world, co_map, (sfVector2i) {x, y});
            if (ABS((co_map[y][x].x - pos.x)) < world->accuracy
            && ABS((co_map[y][x].y - pos.y)) < world->accuracy && world->tools)
                world->map[y][x] += up ? EDIT_SPEED : -EDIT_SPEED;
            if (stat)
                return;
        }
}

void edit_map(sfRenderWindow *window,
            my_world_t *my_world, sfVector2f **coords_map)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && !my_world->tree.select)
        travel_map(sfMouse_getPositionRenderWindow(window),
            my_world, coords_map, true);
    else if (sfMouse_isButtonPressed(sfMouseRight) && !my_world->tree.select)
        travel_map(sfMouse_getPositionRenderWindow(window),
            my_world, coords_map, false);
}

void reset_map(my_world_t *my_world)
{
    for (int y = 0; y < my_world->scale.y; y++)
        for (int x = 0; x < my_world->scale.x; x++)
            my_world->map[y][x] = 0;
}