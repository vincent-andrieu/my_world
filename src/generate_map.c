/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "my_world.h"

void hash_generate(int *tab)
{
    for (int i = 0; i < 256; i++)
        do
            tab[i] = rand() % 256;
        while (already_exist(tab, tab[i], i));
}

static int get_vector(int x, int y, int *tab)
{
    return tab[(x + tab[y % 256]) % 256];
}

static float mathematical_function(float x, float y, float inter)
{
    float tmp = (float) inter * inter * 3 - 2 * inter * inter * inter;

    tmp = tmp * (y - x) + x;
    return tmp;
}

static float noise(float x, float y, int *tab)
{
    int int_x = floor(x);
    int int_y = floor(y);
    float dec_x = (float) x - int_x;
    float dec_y = (float) y - int_y;
    int vector_one = get_vector(int_x, int_y, tab);
    int vector_two = get_vector(int_x + 1, int_y + 1, tab);
    int vector_three = get_vector(int_x + 1, int_y, tab);
    int vector_four = get_vector(int_x, int_y + 1, tab);
    float one = mathematical_function(vector_one, vector_three, dec_x);
    float two = mathematical_function(vector_two, vector_four, dec_x);

    return mathematical_function(one, two, dec_y);
}

int perlin_revenge(int x, int y, int *hash_tab)
{
    float my_x = (float) x / 20;
    float my_y = (float) y / 20;
    float noise_val = 0;
    float amplitude = 1;

    for (int i = 0; i < 4; i++) {
        noise_val += noise(my_x, my_y, hash_tab) * amplitude;
        amplitude /= 2;
        my_x *= 2;
        my_y *= 2;
    }
    return noise_val - 210;
}