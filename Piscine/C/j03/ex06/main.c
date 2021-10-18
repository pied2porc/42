void ft_putstr(char const*);
void ft_putnbr(int);
void ft_swap(int*, int*);

int main()
{
    int a = 2;
    int b = 4;

    ft_putstr("Before:\t"); ft_putnbr(a);
    ft_putstr(", "); ft_putnbr(b);
    ft_swap(&a, &b);
    ft_putstr("\nAfter:\t"); ft_putnbr(a);
    ft_putstr(", "); ft_putnbr(b);

    return 0;
}