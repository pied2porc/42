#include "bistromathique.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char** av)
{
    if (ac != 4) {
        ft_putstr(USAGE_ERR, CERR);
        return EXIT_FAILURE;
    }
    if (check_ops(av[2]) == EXIT_FAILURE ||
        check_base(av[1], av[2]) == EXIT_FAILURE ||
        check_size(av[3]) == EXIT_FAILURE)
        return EXIT_FAILURE;
    
    t_expr expr = { NULL, NULL, 0, av[1], ft_strlen(expr.base), av[2] };
    expr.buf_size = fill_buffer(&expr.buffer, ft_uatoi(av[3]));
    expr.begin = expr.buffer;
    if (!expr.buffer) return EXIT_FAILURE;

    t_number result;
#ifndef _BENCHMARK_TEST
    result = eval_expr(&expr);
#else
    g_time = clock();
    int i = 0;
    for (; i < 1; ++i) {
        result = eval_expr(&expr);
        expr.buffer = expr.begin;
    }
    g_time = clock() - g_time;
    printf("[%f] iteration x%d\n", (double)g_time / CLOCKS_PER_SEC, i);
#endif
    printNumberString(&result, expr.base, expr.ops, TRUE);
    freeNumber(&result);
    free(expr.begin);
    return EXIT_SUCCESS;
}