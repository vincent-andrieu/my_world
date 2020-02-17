/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** sort int int an array
*/

void my_swap(int *a, int *b);

static int is_swap(int *array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (array[i + 1] < array[i])
            return 0;
    }
    return 1;
}

void my_sort_int_array(int *array, int size)
{
    while (!is_swap(array, size)) {
        for (int i = 0; i < size - 1; i++) {
            if (array[i + 1] < array[i])
                my_swap(&array[i], &array[i + 1]);
        }
    }
}
