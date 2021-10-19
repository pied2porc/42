#include <stdlib.h>

void  ft_putstr(char const*);
char* ft_concat_params(int, char* []);

int main(int ac, char* av[])
{
    char* params = ft_concat_params(ac, av);
    ft_putstr(params);

    free(params);
    return 0;
}