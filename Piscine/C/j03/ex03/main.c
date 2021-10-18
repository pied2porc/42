void ft_putchar(char);
void ft_putnbr(int);
void ft_ultimate_div_mod(int*, int*);

int main()
{
    int a = 50;
    int b = 42;

    ft_putnbr(a); ft_putchar('/'); ft_putnbr(b);
    ft_ultimate_div_mod(&a, &b);
    ft_putchar('='); ft_putnbr(a);
    ft_putchar('r'); ft_putnbr(b);
    
    return 0;
}