#include "ft_stock_par.h"
#include <stdlib.h>

int ft_strlen(char const* s)
{
    char const* end = s;
    while (*end)
        ++end;
    return end - s;
}

char* ft_strndup(char const* p, int n)
{
    char* copy = malloc(n + 1);
    if (!copy)
        return 0;

    int i = -1;
    while (++i < n)
        copy[i] = p[i];
    copy[i] = 0;
    return copy;
}

t_stock_par* ft_param_to_tab(int ac, char* av[])
{
    t_stock_par* tab = malloc(sizeof(*tab) * (ac + 1));
    if (!tab)
        return 0;

    int i = -1;
    while (++i < ac) {
        tab[i].size_param = ft_strlen(av[i]);
        tab[i].str = av[i];
        tab[i].copy = ft_strndup(av[i], tab[i].size_param);
        tab[i].tab = ft_split_whitespaces(av[i]);
    }
    tab[i].str = 0;
    return tab;
}