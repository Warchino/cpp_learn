#include <stdio.h>
#include "int_array_list.h"

int main()
{
    int numbers[] = {
        70, 93, 99, 65, 93, 29, 81, 82, 6, 79, 84, 76, 83, 94, 23, 60, 58, 4, 11, 34, 9, 61, 18, 5, 72, 92, 36, 33,
        97, 39, 2, 30, 29, 76, 53, 57, 72, 72, 22, 24, 2, 28, 8, 10, 58, 26, 24, 26, 43, 29, 73, 16, 25, 71, 97, 73, 43,
        16, 13, 17, 26, 62, 9, 30, 37, 78, 65, 50, 96, 72, 91, 36, 68, 17, 58, 39, 4, 54, 97, 19, 41, 88, 50,
        59, 34, 15, 7, 35, 20, 36, 63, 80, 97, 24, 24, 88, 28, 21, 83, 2};

    int_array_list* grouped = get_numbers_grouped_by_units(numbers, 100); //returns an array of int_array_list instances with 10 elements

    show_grouped_numbers(grouped, 10);

    release_grouped_list(grouped);

    //should show:
    // 0: 70, 60, 30, 10, 50, 50, 20
    // 1: 11, 51, 71, 91, 41, …
    // ….
    // ….
    // …
    // 9: 99, 29, 9, 39, 29, 9, 19, ….etc
}
