void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_recursive_factorial(int);

int main()
{
    ft_putnbr(ft_recursive_factorial(0)); ft_putstr("\n");
    ft_putnbr(ft_recursive_factorial(1)); ft_putstr("\n");
    ft_putnbr(ft_recursive_factorial(12)); ft_putstr("\n");
    ft_putnbr(ft_recursive_factorial(15)); ft_putstr("\n");

    return 0;
}