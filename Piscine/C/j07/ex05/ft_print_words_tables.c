void ft_putchar(char);

void ft_print_words_tables(char** tab)
{
    while (*tab) {
        while (**tab) {
            ft_putchar(**tab);
            ++*tab;
        }
        ft_putchar('\n');
        ++tab;
    }
}