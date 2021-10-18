#include <stdlib.h>
void   ft_putstr(char const*);
char** ft_split_whitespaces(char const*);

int main()
{
    char** array =
        ft_split_whitespaces(" \nHello World!\nGoodbye  World!\t\t42 ");

    for (int i = 0; array[i]; ++i) {
        if (i) ft_putstr("\n");
        ft_putstr(array[i]);
        free(array[i]);
    }

    free(array);
    return 0;
}