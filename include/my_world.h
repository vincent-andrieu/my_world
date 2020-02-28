/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world .h file
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Audio.h>
#include <SFML/System/InputStream.h>
#include "my_button.h"
#include "graph.h"

#ifndef MY_WORLD_H_
#define MY_WORLD_H_

#define MSG_INVALID_ARG_NBR "Invalid arguments number\n"
#define EXIT_INVALID_ARG_NBR 84
#define EXIT_ERROR 84

#define ANGLE_X 0.785398
#define ANGLE_Y 0.610865
#define MAP_X 50
#define MAP_Y 50
#define DISPLAY_X 32
#define DISPLAY_Y 32
#define MOUSE_ACC 20
#define EDIT_SPEED 2
#define MOVE_SPEED 50
#define MOUSE_SENSI 10.f
#define ZOOM_EFFECT 0.1

#define SNOW_LEVEL 100
#define STONE_LEVEL 40
#define GRASS_LEVEL 0
#define DIRT_LEVEL -25
#define WATER_LEVEL -20

#define SIZE_LIST 42
#define FILE_PREFIX "./SAVES/MYWORLD"
#define START_SAVE_NBR 0
#define INPUT_WIN_X 1920
#define INPUT_WIN_Y 100

#define BUTT_DEFAULT_SOUND "./ressources/sound.ogg"
#define BUTT_EXIT_SOUND "./ressources/exit.ogg"

typedef struct event_input_t
{
    sfKeyCode code;
    char key;
} event_input_s;

typedef struct button_manage_s
{
    my_button_shape_t *exit;
    my_button_shape_t *restart;
    my_button_shape_t *zoom_in;
    my_button_shape_t *zoom_out;
    my_button_shape_t *size_x_plus;
    my_button_shape_t *size_x_min;
    my_button_shape_t *size_y_plus;
    my_button_shape_t *size_y_min;
    my_button_shape_t *up;
    my_button_shape_t *down;
    my_button_shape_t *left;
    my_button_shape_t *right;
    my_button_shape_t *load;
    my_button_shape_t *save;
    my_button_shape_t *tools;
    my_button_shape_t *tree;
} __attribute__((packed)) button_manage_t;

typedef struct textures_s
{
    sfRenderStates grass;
    sfRenderStates dirt;
    sfRenderStates stone;
    sfRenderStates snow;
    sfRenderStates water;
    sfRenderStates sand;
} textures_t;

typedef struct list_s
{
    struct list_s *next;
    sfVector2i pos;
} list_t;

typedef struct my_sprite_t
{
    sfSprite *sprite;
    sfTexture *texture;
    list_t *list;
    bool select;
} my_sprite_s;

typedef struct my_world_s {
    int **map;
    float zoom;
    sfVector2i scale;
    sfVector2i pos;
    sfVector2i pres_pos;
    textures_t textures;
    sfClock *clock;
    my_sprite_s tree;
    bool tools;
} my_world_t;

int usage(int exit_value, char *binary_name);
bool does_kill_prog(assets_t *assets, my_world_t *my_world);
int my_world(assets_t *assets, char *filepath);
my_world_t *get_my_world(void);
void my_world_destroy(my_world_t *my_world);
sfVector2f **create_twod_map(int **three_d_map, my_world_t *my_world);
void draw_twod_map(assets_t *assets, sfVector2f **map, my_world_t *my_world);
void calc_textures(my_world_t *my_world, sfVector2f **map,
                    sfVector2i coord, sfRenderWindow *window);
sfRenderStates *get_map_texture(int level, textures_t *textures);
void map_stay_in_window(my_world_t *my_world);
void edit_map(sfRenderWindow *window,
            my_world_t *my_world, sfVector2f **coords_map);
sfMusic *start_song(void);
void song_destroy(sfMusic *song);
void reset_map(my_world_t *my_world);
void resize(my_world_t *my_world, button_manage_t *button);
void put_float(int fd, double nbr);
void my_put_fdnbr(int fd, int nb);
textures_t get_textures(void);

button_manage_t *get_button_manage(void);
void refresh_struct(button_manage_t *button, assets_t *assets);
void destroy_struct(button_manage_t *button);
void display_struct(button_manage_t *button, assets_t *assets);
char *get_input(char *title);
int button_effect(my_world_t **my_world, button_manage_t *button,
    assets_t *assets);
int button_load(my_world_t **my_world, button_manage_t *button);
int load_map(my_world_t **my_world, char *filepath);
int button_save(my_world_t *my_world, button_manage_t *button);
int final_save(my_world_t *my_world, int nbr);
int **dup_map(my_world_t *my_world, int size_x, int size_y);
void water_textures(my_world_t *my_world, sfVector2f **map,
                    sfVector2i coord, sfRenderWindow *window);
sfVector2f **water_gest(my_world_t *my_world);
void draw_water(assets_t *assets, sfVector2f **map, my_world_t *my_world);
void free_my_tab(int **tab);
void free_my_map(sfVector2f **map);
bool is_in_triangle(sfVector2f p_one, sfVector2f p_two, sfVector2f p_three,
    sfVector2f p_x);
void tools_select(my_world_t *my_world, button_manage_t *button);
int sound_set(button_manage_t *button);
int set_help_box(button_manage_t *buttons);
void display_help_box(button_manage_t *buttons, sfRenderWindow *window);
sfVertexArray *shadow(sfVector2f *point1, sfVector2f *point2,
    sfVector2f *point3, sfColor color);
sfColor get_color(int point1, int point2, int point3, int point4);
void hash_generate(int *tab);
int perlin_revenge(int x, int y, int *hash_tab);
void smooth_map(int **map);
bool already_exist(int *tab, int value, int max);
my_sprite_s get_sprite(void);
void display_something(assets_t *assets, sfVector2f **map,
    my_world_t *my_world);
list_t *make_list(void);
int add_one(list_t *list, sfVector2i coords);
void distroy(list_t *list);
void my_tree_gest(assets_t *assets, sfVector2f **map, my_world_t *my_world);
void event_set(sfEvent event, my_world_t *world);

#endif