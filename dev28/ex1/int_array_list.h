#ifndef INT_ARRAY_LIST_H
#define INT_ARRAY_LIST_H

#include <stdio.h>

typedef struct
{
    int* numbers;
    size_t size;
} int_array_list;

int_array_list* get_numbers_grouped_by_units(int[], size_t);
void show_grouped_numbers(const int_array_list*, size_t);
void release_grouped_list(int_array_list*);

#endif