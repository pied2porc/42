void ft_putnbr(int);
void ft_putstr(char const*);
void ft_sort_integer_table(int*, int);

int main()
{
    int tab[] = { 0, 2, 1, 3, 4, 5, 6, 7, 8, 9 };
    int size = 10;
    ft_sort_integer_table(tab, size);
    int i = -1;
    while (++i < size) {
        ft_putnbr(tab[i]);
        ft_putstr(" ");
    }
    
    return 0;
}