#include <stdlib.h>

int ft_ultimate_range(int** range, int min, int max)
{
    if (min > max) {
        *range = 0;
        return 0;
    }
    int size = max - min;
    *range = malloc(sizeof(**range) * size);
    if (!(*range))
        return 0;

    int i = 0;
    while (min < max) {
        (*range)[i] = min;
        ++i; ++min;
    }
    return size;
}