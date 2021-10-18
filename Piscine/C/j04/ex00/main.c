void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_iterative_factorial(int);

int main()
{
    ft_putnbr(ft_iterative_factorial(0)); ft_putstr("\n");
    ft_putnbr(ft_iterative_factorial(1)); ft_putstr("\n");
    ft_putnbr(ft_iterative_factorial(8)); ft_putstr("\n");
    ft_putnbr(ft_iterative_factorial(12)); ft_putstr("\n");
    ft_putnbr(ft_iterative_factorial(13)); ft_putstr("\n");

    return 0;
}