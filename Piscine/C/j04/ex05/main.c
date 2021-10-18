void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_sqrt(int);

int main()
{
    ft_putnbr(ft_sqrt(9)); ft_putstr("\n");
    ft_putnbr(ft_sqrt(16)); ft_putstr("\n");
    ft_putnbr(ft_sqrt(42)); ft_putstr("\n");
    ft_putnbr(ft_sqrt(81)); ft_putstr("\n");

    return 0;
}