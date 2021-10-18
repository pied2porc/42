#pragma warning(disable:4100)
#include "ft_adv_oop.h"
#include "ft_oop.h"

int ft_add(int x, int y) { return x + y; }

int ft_sub(int x, int y) { return x - y; }

int ft_mul(int x, int y) { return x * y; }

int ft_div(int x, int y) { return !y ? 0 : x / y; }

int ft_mod(int x, int y) { return !y ? 0 : x % y; }

int ft_usage(int x, int y)
{
    ft_putstr("error: only [ - + * / % ] are accepted.\n");
    return 0;
}

void do_op(int x, int y, char* op)
{
    if (!y && !ft_strcmp(op, "/")) {
        ft_putstr("Stop: division by zero\n");
        return;
    }
    if (!y && !ft_strcmp(op, "%")) {
        ft_putstr("Stop: modulo by zero\n");
        return;
    }
    t_opp* ptr = g_opptab - 1;
    while ((++ptr)->f != ft_usage && ft_strcmp(ptr->op, op));
    if (ptr->f == ft_usage) {
        ptr->f(x, y);
        return;
    }
    ft_putnbr(ptr->f(x, y));
    ft_putstr("\n");
}