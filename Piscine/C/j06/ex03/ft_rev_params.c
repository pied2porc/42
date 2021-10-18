#include "ft.h"

int main(int ac, char* av[])
{
    while(--ac){
        ft_putstr(av[ac]);
        ft_putchar('\n');
    }
    return 0;
}