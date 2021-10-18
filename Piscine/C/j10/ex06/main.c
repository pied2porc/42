#include "ft_do-op.h"

int main(int ac, char* av[])
{
    if (ac != 4)
        return -1;
    int x = ft_atoi(av[1]);
    int y = ft_atoi(av[3]);

    if (*av[2] == '/' && !y) {
        ft_putstr("Stop: division by zero\n");
        return -1;
    }
    if (*av[2] == '%' && !y) {
        ft_putstr("Stop: modulo by zero\n");
        return -1;
    }
    int nb = do_op(x, y, av[2]);
    ft_putnbr(nb);

    return 0;
}