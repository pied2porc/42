#include <stdlib.h>
void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_ultimate_range(int**, int, int);

int main()
{
    int min = -42;
    int max = 42;

    int *array = 0;
    ft_putstr("range: "); ft_putnbr(ft_ultimate_range(&array, min, max));
    ft_putstr("\n");
    for (int i = 0; i < max - min; ++i) {
        ft_putnbr(array[i]);
        ft_putstr(" ");
    }

    free(array);
    return 0;
}