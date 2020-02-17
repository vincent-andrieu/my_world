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


#define MAP_X 6
#define MAP_Y 6

#define DISPLAY_X 10
#define DISPLAY_Y 10

sfVector2f project_iso_point(int x, int y, int z) {
    sfVector2f my_2d_vector = {0};

    my_2d_vector.x = cos(ANGLE_X) * x - cos(ANGLE_X) * y;
    my_2d_vector.y = sin(ANGLE_Y) * y + sin(ANGLE_Y) * x - z;
    return my_2d_vector;
}

sfVector2f **create_2d_map(int **three_d_map)
{
    sfVector2f **my_map = malloc(sizeof(sfVector2f *) * (MAP_Y + 1));

    if (!my_map)
        return NULL;
    my_map[MAP_Y] = NULL;
    for (int i = 0; i < MAP_Y; i++) {
        my_map[i] = malloc(sizeof(sfVector2f) * MAP_X);
        if (!my_map[i])
            return NULL;
    }
    for (int y = 0; y < MAP_Y; y++) {
        for (int x = 0; x < MAP_X; x++)
            my_map[y][x] = project_iso_point(x, y, three_d_map[y][x]);
    }
    return my_map;
}

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfWhite};
    sfVertex vertex2 = {.position = *point2, .color = sfWhite};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType ( vertex_array , sfLinesStrip ) ;
    return(vertex_array);
}

int draw_2d_map(sfRenderWindow *window, sfVector2f **map)
{
    sfVertexArray *vertexarray;

    for (int y = 0; y < MAP_Y; y++) {
        for (int x = 0; x < MAP_X; x++) {
            vertexarray = create_line (&map[y][x], &map[y][x + 1]);
            sfRenderWindow_drawVertexArray(window, vertexarray, NULL);
            sfVertexArray_destroy(vertexarray);
            vertexarray = create_line (&map[y + 1][x], &map[y][x]);
            sfRenderWindow_drawVertexArray(window, vertexarray, NULL);
            sfVertexArray_destroy(vertexarray);
        }
    }
    return 0;
}

int bootstrap(assets_t *assets)
{
    int **map = malloc(sizeof(int *) * (MAP_Y + 1));
    map[MAP_Y] = NULL;
    for (int y = 0; y < MAP_Y; y++) {
        map[y] = malloc(sizeof(int) * MAP_X);
        for (int x = 0; x < MAP_X; x++)
            map[y][x] = 0;
    }

    sfVector2f **my_map = create_2d_map(map);
    draw_2d_map(assets->window, my_map);
    for (int y = 0; y < MAP_Y; y++) {
        for (int x = 0; x < MAP_X; x++)
            printf("x: %f|y: %f\n", my_map[y][x].x, my_map[y][x].y);
        free(my_map[y]);
    }
    free(my_map);
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);
    return EXIT_SUCCESS;
}