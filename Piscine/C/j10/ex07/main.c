#include <stdlib.h>

void   ft_putstr(char const*);
char** ft_split_whitespaces(char const*);
void   ft_sort_wordtab(char**);

int main()
{
    char** tab = ft_split_whitespaces(" Hello World!\t\t Goodbye  World! 42 \t");
    ft_sort_wordtab(tab);

    int i = -1;
    while (tab && tab[++i]) {
        ft_putstr(tab[i]); ft_putstr("\n");
        free(tab[i]);
    }
    free(tab);
    return 0;
}