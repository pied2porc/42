void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_recursive_power(int, int);

int main()
{
    ft_putnbr(ft_recursive_power(42, 0)); ft_putstr("\n");
    ft_putnbr(ft_recursive_power(42, 3)); ft_putstr("\n");

    return 0;
}