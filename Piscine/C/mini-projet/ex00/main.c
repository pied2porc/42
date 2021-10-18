#include <io.h>
#include <stdlib.h>

void sastantua(int size);

void ft_putchar(char c)
{
    _write(1, &c, 1);
}

int main(int ac, char* av[])
{
    if (ac < 2) {
        _write(1, "usage: sastantua <size> [...]\n", 30);
        return EXIT_FAILURE;
    }
    for (int i = 1; i < ac; ++i)
        sastantua(atoi(av[i]));
    return EXIT_SUCCESS;
}