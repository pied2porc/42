#include "ft_error.h"
#include "ft_display_file.h"

int main(int ac, char* av[])
{
    if (ac == 2)
        ft_display_file(av[1]);
    else if (ac == 1)
        ft_print_error("File name missing.\n");
    else if (ac > 2)
        ft_print_error("Too many argument.\n");
    return 0;
}