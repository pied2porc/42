#include <stdlib.h>

int* ft_range(int min, int max)
{
    if (min > max)
        return 0;

    int* array = malloc(sizeof(*array) * (max - min));
    if (!array)
        return 0;

    int i = 0;
    while (min < max) {
        array[i] = min;
        ++i; ++min;
    }
    return array;
}