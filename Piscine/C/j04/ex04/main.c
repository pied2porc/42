void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_fibonacci(int);

int main()
{
    ft_putnbr(ft_fibonacci(-42)); ft_putstr("\n");
    ft_putnbr(ft_fibonacci(0)); ft_putstr("\n");
    ft_putnbr(ft_fibonacci(1)); ft_putstr("\n");
    ft_putnbr(ft_fibonacci(2)); ft_putstr("\n");
    ft_putnbr(ft_fibonacci(3)); ft_putstr("\n");
    ft_putnbr(ft_fibonacci(4)); ft_putstr("\n");
    ft_putnbr(ft_fibonacci(11)); ft_putstr("\n");
    ft_putnbr(ft_fibonacci(42)); ft_putstr("\n");

    return 0;
}