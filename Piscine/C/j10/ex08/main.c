#include <stdlib.h>

void   ft_putstr(char const*);
int    ft_strcmp(char const*, char const*);
char** ft_split_whitespaces(char const*);
void   ft_advanced_sort_wordtab(char**, int(*)(char const*, char const*));

int main()
{
    char** tab = ft_split_whitespaces(" Hello World!\t\t Goodbye  World! 42 \t");
    ft_advanced_sort_wordtab(tab, ft_strcmp);

    int i = -1;
    while (tab && tab[++i]) {
        ft_putstr(tab[i]); ft_putstr("\n");
        free(tab[i]);
    }
    free(tab);
    return 0;
}