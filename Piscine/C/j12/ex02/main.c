#define _CRT_SECURE_NO_WARNINGS
#include "ft_error.h"
#include "ft_option.h"
#include "ft_tail.h"
#include <stdlib.h>
#include <stdio.h>
#include <io.h>

int main(int ac, char* av[])
{
    t_opt optTab[max_options] = { {-1, NULL} };
    if (ft_parse_options(ac, av, optTab) == EXIT_FAILURE)
        return EXIT_FAILURE;
        
    char** files = ft_get_filenames(ac, av, optTab);
    if (!files) return EXIT_FAILURE;

    int buf_size = ft_get_buffer_size(optTab);
    if (buf_size <= 0) {
        if (buf_size == -1)
            ft_print_arg_error(av[0], optTab[c_opt].arg,
                "invalid number of bytes:");
        return EXIT_FAILURE;
    }
    char* buf = malloc(buf_size + 1);
    if (!buf) {
        ft_print_error("ft_tail: out of memory\n");
        return EXIT_FAILURE;
    }
    ft_tail(buf, buf_size, files, optTab, av[0]);
    free(buf);
    free(files);
    return EXIT_SUCCESS;
}