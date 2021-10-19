void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_compact(char const**, int);

int main()
{
    char const* tab[] = { 0, "abc", 0, 0, "def", 0, "123", "456", 0, 0 };

    int i = -1;
    while (tab[++i]) {
        ft_putstr(tab[i]); ft_putstr("<");
    }
    ft_putstr("<\n");

    int new_len = ft_compact(tab, 10);
    ft_putnbr(new_len); ft_putstr("\n");

    i = -1;
    while (++i < new_len) {
        ft_putstr(tab[i]); ft_putstr("<");
    }
    ft_putstr("<\n");

    return 0;
}