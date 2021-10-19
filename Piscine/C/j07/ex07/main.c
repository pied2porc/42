#include <stdlib.h>

void   ft_putstr(char const*);
char** ft_split(char const*, char const*);

int main()
{
    char** array =
        ft_split(" \nHello World! \n\n Goodbye  World!\t\t  \t42 ",
        " \n\t");
    for (int i = 0; array[i]; ++i) {
        ft_putstr(array[i]); ft_putstr("\n");
        free(array[i]);
    }

    array = ft_split("testxdexdecoupexdexchainexxxdexxxcaracteresxx", "x");
    for (int i = 0; array[i]; ++i) {
        ft_putstr(array[i]); ft_putstr("\n");
        free(array[i]);
    }
    free(array);
    return 0;
}