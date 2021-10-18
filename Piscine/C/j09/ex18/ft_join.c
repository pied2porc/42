#include <stdlib.h>

static int ft_strlen(char const* s)
{
    int len = -1;
    while (s[++len]);
    return len;
}

static char* ft_strcpy(char* dst, char const* src)
{
    char* cpy = dst;
    while (*src) {
        *dst = *src;
        ++dst; ++src;
    }
    *dst = *src;
    return cpy;
}

static char* ft_strcat(char* dst, char const* src)
{
    int dst_len = ft_strlen(dst);
    int i = -1;
    while (src[++i])
        dst[dst_len + i] = src[i];
    dst[dst_len + i] = '\0';
    return dst;
}

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