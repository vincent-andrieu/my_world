/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** tiles
*/

#include "my_world.h"

static bool get_vector(sfVector2f p_one, sfVector2f p_two, sfVector2f p_x)
{
    float val = (p_one.x - p_x.x) * (p_two.y - p_x.y);

    val -= (p_one.y - p_x.y) * (p_two.x - p_x.x);
    if (val > 0)
        return true;
    return false;
}

void tools_select(my_world_t *my_world, button_manage_t *button)
{
    if (button_ispressed(button->tools) && button->tools->is_activate) {
        if (my_world->tools)
            my_world->tools = false;
        else
            my_world->tools = true;
        button->tools->is_activate = false;
    }
}

bool is_in_triangle(sfVector2f p_one, sfVector2f p_two, sfVector2f p_three,
    sfVector2f p_x)
{
    int i;
    bool tab[3];

    tab[0] = get_vector(p_one, p_two, p_x);
    tab[1] = get_vector(p_two, p_three, p_x);
    tab[2] = get_vector(p_three, p_one, p_x);
    if (tab[0] && tab[1] && tab[2])
        return true;
    if (!tab[0] && !tab[1] && !tab[2])
        return true;
    return false;
}