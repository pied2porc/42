#include <stdlib.h>
void ft_putnbr(int);
void ft_putstr(char const*);
int* ft_range(int, int);

int main()
{
    int min = -42;
    int max = 42;

    int* array = ft_range(min, max);
    for (int i = 0; i < max - min; ++i) {
        ft_putnbr(array[i]);
        ft_putstr(" ");
    }

    free(array);
    return 0;
}