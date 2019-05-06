#include <stdlib.h>
#include "int_array_list.h"

void init_int_array_list(int_array_list* ial)
{
    for (size_t i = 0; i < 10; i++)
    {
        ial[i].numbers = malloc(0);
        ial[i].size = 0;
    }
}

void add_number_to_array(int_array_list* ial, int* value)
{
    
    ial->numbers = (int*)realloc(ial->numbers, sizeof(int)*(ial->size+1));
    ial->numbers[ial->size] = *value;
    ial->size++;
}

int_array_list* get_numbers_grouped_by_units(int array[], size_t n)
{
    int_array_list* arrList = (int_array_list*)malloc(10 * sizeof(int_array_list));;
    init_int_array_list(arrList);
    
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            if (array[i] % 10 == j)
            {
                add_number_to_array(&(arrList[j]), &array[i]);
                break;
            }
        }
    }
    return arrList;
}

void show_grouped_numbers(const int_array_list* ial, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        int* al = ial[i].numbers;
        size_t size = ial[i].size;
        printf("%lu:", i);
        for (size_t i = 0; i < size; i++)
        {
            printf("%d ",al[i]);
        }
        puts("");
        printf("Size of element->%lu\n", size);
    }

}

void release_grouped_list(int_array_list* ial)
{
    for (size_t i = 0; i < 10; i++)
    {
        free(ial[i].numbers);
    }
    free(ial);
    ial = NULL;
}
