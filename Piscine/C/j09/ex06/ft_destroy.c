#include <stdlib.h>

void ft_destroy(char*** factory)
{
    int i = -1;
    while (factory[++i]) {
        int j = -1;
        while (factory[i][++j])
            free(factory[i][j]);
        free(factory[i]);
    }
    free(factory);
}