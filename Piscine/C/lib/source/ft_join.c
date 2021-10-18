#include "ft.h"
#include <stdlib.h>

char* ft_join(char const** tab, char const* sep)
{
    int len = 0;
    int sep_len = ft_strlen(sep);
    int i = -1;
    while (tab[++i]) {
        len += ft_strlen(tab[i]);
        len += sep_len;
    }
    char* join = malloc(len + 1);
    if (!join) return NULL;

    i = 0;
    ft_strcpy(join, tab[i]);
    while (tab[++i]) {
        if (i > 0)
            ft_strcat(join, sep);
        ft_strcat(join, tab[i]);
    }
    return join;
}