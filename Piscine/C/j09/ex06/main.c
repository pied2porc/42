#include "ft_ultimator.h"
#include <stdlib.h>

void  ft_putstr(char const*);
char* ft_strdup(char const*);
void  ft_destroy(char***);

int main()
{
    char** s = malloc(sizeof(char*) * 4);
    s[0] = ft_strdup("abc");
    s[1] = ft_strdup("def");
    s[2] = ft_strdup("ghi");
    s[3] = 0;

    char** n = malloc(sizeof(char*) * 4);
    n[0] = ft_strdup("123");
    n[1] = ft_strdup("456");
    n[2] = ft_strdup("789");
    n[3] = 0;

    char*** factory = malloc(sizeof(char**) * 3);
    factory[0] = s; factory[1] = n; factory[2] = 0;

    int i = -1;
    while (factory[0][++i]) {
        ft_putstr(factory[0][i]); ft_putstr("=");
        ft_putstr(s[i]); ft_putstr("\n");
    }
    i = -1;
    while (factory[1][++i]) {
        ft_putstr(factory[1][i]); ft_putstr("=");
        ft_putstr(n[i]); ft_putstr("\n");
    }

    ft_destroy(factory);
    return 0;
}