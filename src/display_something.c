/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my_world.h"

my_sprite_s get_sprite(void)
{
    my_sprite_s my_struct = {0};

    my_struct.sprite = sfSprite_create();
    my_struct.texture = sfTexture_createFromFile("./ressources/tree.png", NULL);
    sfSprite_setTexture(my_struct.sprite, my_struct.texture, sfTrue);
    my_struct.sprite_jaaj = sfSprite_create();
    my_struct.texture_jaaj =
    sfTexture_createFromFile("./ressources/tree.png", NULL);
    sfSprite_setTexture(my_struct.sprite_jaaj, my_struct.texture_jaaj, sfTrue);
    my_struct.list = make_list();
    my_struct.select = false;
    return my_struct;
}

static sfVector2i get_tree_select(assets_t *assets, sfVector2f **map,
    my_world_t *world)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(assets->window);

    for (int y = 0; y < world->scale.y; y++)
        for (int x = 0; x < world->scale.x; x++)
            if (map[y][x].x - mouse.x > -MOUSE_ACC
            && map[y][x].x - mouse.x < MOUSE_ACC
            && map[y][x].y - mouse.y > -MOUSE_ACC
            && map[y][x].y - mouse.y < MOUSE_ACC) {
                return (sfVector2i) {x, y};
            }
    return (sfVector2i) {-1, -1};
}

static void destroy_it(list_t *list, sfVector2i coords)
{
    list_t *prev = list->next;
    list_t *end;

    if (!prev)
        return;
    end = prev->next;
    while (end) {
        if (end->pos.x == coords.x && end->pos.y == coords.y) {
            prev->next = end->next;
            free(end);
            return;
        }
        prev = end;
        end = end->next;
    }
}

void my_tree_gest(assets_t *assets, sfVector2f **map, my_world_t *my_world)
{
    sfVector2i tree;

    if (sfMouse_isButtonPressed(sfMouseLeft) && my_world->tree.select) {
        tree = get_tree_select(assets, map, my_world);
        if (tree.x != -1 && tree.y != -1)
            if (my_world->map[tree.y][tree.x] > WATER_LEVEL)
                add_one(my_world->tree.list, tree);
    }
    else if (sfMouse_isButtonPressed(sfMouseRight)) {
        tree = get_tree_select(assets, map, my_world);
        if (tree.x != -1 && tree.y != -1)
            destroy_it(my_world->tree.list, tree);
    }
}