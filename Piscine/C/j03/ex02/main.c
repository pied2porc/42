void ft_putchar(char);
void ft_putnbr(int);
void ft_div_mod(int, int, int*, int*);

int main()
{
    int x = 50;
    int y = 42;
    int div = 0;
    int mod = 0;
    ft_div_mod(x, y, &div, &mod);
    ft_putnbr(x); ft_putchar('/'); ft_putnbr(y);
    ft_putchar('='); ft_putnbr(div);
    ft_putchar('r'); ft_putnbr(mod);

    return 0;
}