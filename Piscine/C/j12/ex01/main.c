#include "ft_display.h"
#include "ft_error.h"

int main(int ac, char* av[])
{
    if (ac == 1) {
        ft_display_stdin();
        return 0;
    }
    int c = 0;
    while (++c < ac)
        if (*av[c] == '-')
            ft_display_stdin();
        else
            ft_display_file(av[c]);
    return 0;
}