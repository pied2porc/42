#include <stdlib.h>

char* ft_strndup(char const* s, int n)
{
    char* dup = malloc(n + 1);
    if (!dup) return 0;

    int i = -1;
    while (++i < n)
        dup[i] = *(s + i);
    dup[i] = 0;
    return dup;
}