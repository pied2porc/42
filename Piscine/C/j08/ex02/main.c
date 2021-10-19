#include "ft_abs.h"

int  ft_atoi(char const*);
void ft_putnbr(int);

int main(int ac, char** av)
{
    if (ac != 3) return 1;

    int x = ft_atoi(av[1]);
    int y = ft_atoi(av[2]);
    ft_putnbr(ABS(x - y));

    return 0;
}