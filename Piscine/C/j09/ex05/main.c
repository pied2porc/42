void ft_putchar(char);
void ft_putnbr(int);
int  ft_antidote(int, int, int);

int main()
{
    ft_putnbr(ft_antidote(11, 42, 22)); ft_putchar(' ');
    ft_putnbr(ft_antidote(11, 22, 42)); ft_putchar(' ');
    ft_putnbr(ft_antidote(42, 11, 22)); ft_putchar(' ');
    ft_putnbr(ft_antidote(22, 42, 11)); ft_putchar(' ');
    return 0;
}