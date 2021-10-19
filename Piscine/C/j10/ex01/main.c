#include <io.h>
#include <stdlib.h>

void ft_foreach(int*, int, void(*)(int));

void ft_putnbr(int n)
{
    if (n >= 10 || n <= -10)
        ft_putnbr(n / 10);
    n %= 10;
    if (n < 0) {
        _write(1, "-", 1);
        n = -n;
    }
    n += '0';
    _write(1, &n, 1);
}

int main()
{
    int* tab = malloc(sizeof(int) * 1337);
    int i = -1;
    while (++i < 1337)
        tab[i] = i + 1;
    ft_foreach(tab, 1337, &ft_putnbr);

    free(tab);
    return 0;
}