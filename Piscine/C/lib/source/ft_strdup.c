#include <stdlib.h>

char* ft_strdup(char const* s)
{
    char const* ptr = s - 1;
    while (*(++ptr));

    char* dup = malloc((ptr - s) + 1);
    if (!dup) return 0;

    ptr = s - 1;
    while (*(++ptr))
        dup[ptr - s] = *ptr;
    dup[ptr - s] = 0;
    return dup;
}