#include "ft_adv_oop.h"

int main(int ac, char* av[])
{
    if (ac != 4)
        return -1;
    do_op(ft_atoi(av[1]), ft_atoi(av[3]), av[2]);
    
    return 0;
}