#include "ft_error.h"
#include "ft_option.h"
#include <stdlib.h>

char** ft_get_filenames(int ac, char* av[], t_opt* optTab)
{
    char** files = malloc(sizeof(char*) * ac);
    if (!files) return NULL;

    int i = 0;
    int f = -1;
    while (++i < ac) {
        if (av[i][0] != '-' && av[i] != optTab[c_opt].arg)
            files[++f] = av[i];
    }
    files[++f] = 0;
    return files;
}

int ft_get_num_bytes(char const* s)
{
    int const b = 512;
    int const k = 1024;
    int const m = k * k;

    if (*s == '+' || *s == '-') ++s;
    if (*s == 'b') return b;
    if (*s == 'k') return k;
    if (*s == 'm') return m;

    int num = ft_atoi(s);
    while (*s) ++s;
    if (*(s - 1) == 'b') return num * b;
    if (*(s - 1) == 'k') return num * k;
    if (*(s - 1) == 'm') return num * m;
    return num;
}

/**
 * Num bytes can be preceded by no more than one sign character
 * and followed by a unit character.
*/
int ft_check_num_bytes(char const* s)
{
    char const* n = s;
    while (*n == '+' || *n == '-') ++n;
    if (n > s + 1)
        return EXIT_FAILURE;

    while (*n >= '0' && *n <= '9') ++n;
    if (!*n || (*n == 'b' || *n == 'k' || *n == 'm') && !*(n + 1))
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}

int ft_get_buffer_size(t_opt* optTab)
{
    if (!optTab[c_opt].arg) return BUF_SIZE;
    if (ft_check_num_bytes(optTab[c_opt].arg) == EXIT_FAILURE)
        return -1;
    return ft_get_num_bytes(optTab[c_opt].arg);
}

int ft_get_optArg(int* i, int ac, char* av[], t_opt* optTab)
{
    if (av[*i][2] != '\0')       // arg is in the same token
        optTab->arg = av[*i] + 2;
    else if (*i + 1 < ac)        // arg is in the next token
        optTab->arg = av[++*i];
    else {
        ft_print_arg_error(av[0], av[*i] + 1,
            "option requires an argument --");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int ft_parse_options(int ac, char* av[], t_opt* optTab)
{
    int i = 0;
    while (++i < ac) {
        if (av[i][0] == '-') {
            switch (av[i][1]) {
            case 'c':
                optTab[c_opt].idx = i;
                if (ft_get_optArg(&i, ac, av, &optTab[c_opt]) == EXIT_FAILURE)
                    return EXIT_FAILURE;
                break;
            default:
                ft_print_arg_error(av[0], av[i] + 1, "invalid option --");
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}