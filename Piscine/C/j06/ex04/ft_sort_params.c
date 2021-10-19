#include "ft.h"

int main(int ac, char* av[])
{
    int cur = 1;
    while (++cur < ac) {
        char* toInsert = av[cur];
        int   prev = cur;
        while (--prev > 0 && ft_strcmp(toInsert, av[prev]) < 0)
            av[prev + 1] = av[prev];
        av[prev + 1] = toInsert;
    }
    cur = 0;
    while (++cur < ac) {
        ft_putstr(av[cur]);
        ft_putchar('\n');
    }
    return 0;
}