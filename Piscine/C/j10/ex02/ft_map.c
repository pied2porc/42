#include <stdlib.h>

int* ft_map(int* tab, int length, int(*f)(int))
{
    int* res = malloc(sizeof(*res) * length);
    if (!res) return NULL;
    
    int i = -1;
    while (++i < length)
        res[i] = f(tab[i]);
    return res;
}