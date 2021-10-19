#include <stdlib.h>

void ft_putnbr(int);
void ft_putstr(char const*);
int* ft_map(int*, int, int(*)(int));

int ft_add_one(int n) { return n + 1; }

int main()
{
    int* tab = malloc(sizeof(*tab) * 1337);
    int i = -1;
    while (++i < 1337)
        tab[i] = i + 1;

    int* res = ft_map(tab, 1337, &ft_add_one);

    i = -1;
    while (++i < 1337) {
        ft_putnbr(res[i]); ft_putstr(" ");
    }

    free(tab);
    free(res);
    return 0;
}