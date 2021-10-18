#include "ft.h"

int main(int ac, char* av[])
{
    int i = 0;
    while (++i < ac){
        ft_putstr(av[i]);
        ft_putchar('\n');
    }
    return 0;
}