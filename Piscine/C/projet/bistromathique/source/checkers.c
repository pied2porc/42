#include "bistromathique.h"

int check_ops(char const* ops)
{
    if (ft_strlen(ops) != 7) {
        ft_putstr(OPS_ARG_ERR, CERR);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int check_base(char const* base, char const* ops)
{
    int pos = 0;
    while (base[pos]) {
        if (ft_contains(ops, base[pos]) >= 0) {
            ft_putstr(BASE_ARG_ERR, CERR);
            return EXIT_FAILURE;
        }
        ++pos;
    }
    if (pos < 2) {
        ft_putstr(BASE_ARG_ERR, CERR);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int check_size(char const* size)
{
    while (*size) {
        if (*size < '0' || *size > '9') {
            ft_putstr(READ_SIZE_ERR, CERR);
            return EXIT_FAILURE;
        }
        ++size;
    }
    return EXIT_SUCCESS;
}