#include "ft_do-op.h"

int ft_add(int x, int y) { return x + y; }

int ft_sub(int x, int y) { return x - y; }

int ft_mul(int x, int y) { return x * y; }

int ft_div(int x, int y) { return !y ? 0 : x / y; }

int ft_mod(int x, int y) { return !y ? 0 : x % y; }

int do_op(int x, int y, char const* op)
{
    static t_op op_tab[] = {
    {"+", ft_add},
    {"-", ft_sub},
    {"*", ft_mul},
    {"/", ft_div},
    {"%", ft_mod},
    {"" , 0} };

    t_op* ptr = op_tab - 1;
    while (*(++ptr)->op != *op && ptr->f);
    return (!ptr->f ? 0 : ptr->f(x, y));
}