/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my.h"
#include "my_world.h"

event_input_s const key_tab[] = {
    (event_input_s) {sfKeyA, 'A'},
    (event_input_s) {sfKeyB, 'B'},
    (event_input_s) {sfKeyC, 'C'},
    (event_input_s) {sfKeyD, 'D'},
    (event_input_s) {sfKeyE, 'E'},
    (event_input_s) {sfKeyF, 'F'},
    (event_input_s) {sfKeyG, 'G'},
    (event_input_s) {sfKeyH, 'H'},
    (event_input_s) {sfKeyI, 'I'},
    (event_input_s) {sfKeyJ, 'J'},
    (event_input_s) {sfKeyK, 'K'},
    (event_input_s) {sfKeyL, 'L'},
    (event_input_s) {sfKeyM, 'M'},
    (event_input_s) {sfKeyN, 'N'},
    (event_input_s) {sfKeyO, 'O'},
    (event_input_s) {sfKeyP, 'P'},
    (event_input_s) {sfKeyQ, 'Q'},
    (event_input_s) {sfKeyR, 'R'},
    (event_input_s) {sfKeyS, 'S'},
    (event_input_s) {sfKeyT, 'T'},
    (event_input_s) {sfKeyU, 'U'},
    (event_input_s) {sfKeyV, 'V'},
    (event_input_s) {sfKeyW, 'W'},
    (event_input_s) {sfKeyX, 'X'},
    (event_input_s) {sfKeyY, 'Y'},
    (event_input_s) {sfKeyZ, 'Z'},
    (event_input_s) {sfKeyNum0, '0'},
    (event_input_s) {sfKeyNum1, '1'},
    (event_input_s) {sfKeyNum2, '2'},
    (event_input_s) {sfKeyNum3, '3'},
    (event_input_s) {sfKeyNum4, '4'},
    (event_input_s) {sfKeyNum5, '5'},
    (event_input_s) {sfKeyNum6, '6'},
    (event_input_s) {sfKeyNum7, '7'},
    (event_input_s) {sfKeyNum8, '8'},
    (event_input_s) {sfKeyNum9, '9'},
    (event_input_s) {sfKeySlash, '/'},
    (event_input_s) {sfKeyBackslash, '\\'},
    (event_input_s) {sfKeySpace, ' '},
    (event_input_s) {sfKeyHyphen, '-'},
    (event_input_s) {sfKeyTilde, '~'},
    (event_input_s) {sfKeyQuote, '\''}
};

static void text_display(sfRenderWindow *window, sfVector2f position, char *str)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./ressources/ChunkfiveEx.ttf");

    if (!font)
        return;
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
}

static char *add_char(char *str, char c)
{
    char *ret = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i;

    if (!ret)
        return NULL;
    for (i = 0; str[i] != '\0'; i++)
        ret[i] = str[i];
    ret[i] = c;
    ret[i + 1] = '\0';
    free(str);
    return ret;
}

static void remove_char(char *str)
{
    int i;

    for (i = 0; str[i + 1] != '\0'; i++);
    str[i] = '\0';
}

static char *text_input(sfRenderWindow *window, sfEvent event, char *str)
{
    if (event.type == sfEvtClosed || (event.type == sfEvtKeyReleased
        && (event.key.code == sfKeyEscape || event.key.code == sfKeyEnter))) {
        sfRenderWindow_close(window);
        return str;
    }
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyBackspace) {
            remove_char(str);
            return str;
        }
        for (int i = 0; i < SIZE_LIST; i++) {
            if (event.key.code == key_tab[i].code)
                str = add_char(str, key_tab[i].key);
        }
    }
    return str;
}

char *get_input(char *title)
{
    sfEvent event;
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode)
        {INPUT_WIN_X, INPUT_WIN_Y, 32}, title, sfResize | sfClose, NULL);
    char *str = malloc(sizeof(char) * 1);

    if (!str)
        return NULL;
    str[0] = '\0';
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            str = text_input(window, event, str);
            if (!str)
                return NULL;
        }
        if (str[0])
            text_display(window, (sfVector2f) {0, 0}, str);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    sfRenderWindow_destroy(window);
    return str;
}