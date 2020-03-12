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
#define EDIT_SPEED 2
#define MOVE_SPEED 50
#define MOUSE_SENSI 10.f
#define ZOOM_EFFECT 0.1
#define SPEED_ANGLE 0.1

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

#define DEF_MOUSE_ACC 20
#define PREC_COLOR sfRed
static const sfVector2i acc_pos_from = {50, 900};
static const sfVector2i acc_pos_to = {150, 900};

#define X_AXES 100
#define Y_AXES 120

typedef struct sfVector3i_s
{
    int x;
    int y;
    int z;
} sfVector3i;

typedef struct cube_s
{
    sfVector3i a;
    sfVector3i b;
    sfVector3i c;
    sfVector3i d;
    sfVector3i e;
    sfVector3i f;
    sfVector3i g;
    sfVector3i h;
} cube_t;

typedef struct proj_cube_s
{
    sfVector2f a;
    sfVector2f b;
    sfVector2f c;
    sfVector2f d;
    sfVector2f e;
    sfVector2f f;
    sfVector2f g;
    sfVector2f h;
} proj_cube_t;

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
    my_button_shape_t *angle_x_plus;
    my_button_shape_t *angle_y_plus;
    my_button_shape_t *angle_x_min;
    my_button_shape_t *angle_y_min;
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
    sfSprite *sprite_kelp;
    sfTexture *texture_kelp;
    sfSprite *sprite_jaaj;
    sfTexture *texture_jaaj;
    sfSprite *sprite_fish;
    sfTexture *texture_fish;
    list_t *list;
    bool select;
} my_sprite_s;

typedef struct dog_s
{
    sfVector2i pos;
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    bool status;
} dog_t;

typedef struct my_world_s {
    int **map;
    float zoom;
    float accuracy;
    sfVector2f angle;
    sfVector2i scale;
    sfVector2i pos;
    sfVector2i pres_pos;
    textures_t textures;
    my_sprite_s tree;
    bool tools;
    bool mode;
    dog_t dog;
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
int button_save(my_world_t *my_world, button_manage_t *button, bool force);
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
void smooth_map(my_world_t *my_world);
bool already_exist(int *tab, int value, int max);
my_sprite_s get_sprite(void);
void display_something(assets_t *assets, sfVector2f **map,
    my_world_t *my_world);
list_t *make_list(void);
int add_one(my_world_t *world, sfVector2i coords);
void distroy(list_t *list);
void my_tree_gest(assets_t *assets, sfVector2f **map, my_world_t *my_world);
void event_set(sfEvent event, my_world_t *world, assets_t *assets);
void display_player(sfRenderWindow *window, sfVector2f **map,
                    my_world_t *my_world);
void display_something(assets_t *assets, sfVector2f **map,
    my_world_t *my_world);
void display_precision(float accuracy, assets_t *assets);
void my_precision(my_world_t *my_world, assets_t *assets);
void map_angle_gest(my_world_t *my_world, button_manage_t *button);
dog_t get_dog(void);
void dog_destroy(dog_t dog);
void dog_finder(my_world_t *my_world);

sfVertexArray *display_texture(sfVector2f *point1, sfVector2f *point2,
    sfVector2f *point3);
void display_my_cube(assets_t *assets, my_world_t *my_world);
sfVector2f project_cube(sfVector3i coord, my_world_t *my_world,
    sfVector2i pos, float zoom);
sfVertexArray *create_edge(sfVector2f *point1, sfVector2f *point2,
    sfColor color);
void display_end(proj_cube_t cube, assets_t *assets, my_world_t *world);
void display_face_one(proj_cube_t cube, assets_t *tools, my_world_t *world);
void display_face_two(proj_cube_t cube, assets_t *assets, my_world_t *world);
void display_my_entity(assets_t *assets, my_world_t *my_world);
sfSprite *init_background(void);
char *get_map(const char *filepath);
void map_gen(my_world_t *my_world);

#endif