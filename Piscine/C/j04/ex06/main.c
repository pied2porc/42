void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_is_prime(int);

int main()
{
    ft_putnbr(0); ft_putstr("\t");
    ft_putnbr(ft_is_prime(0)); ft_putstr("\n");
    ft_putnbr(1); ft_putstr("\t");
    ft_putnbr(ft_is_prime(1)); ft_putstr("\n");
    ft_putnbr(2); ft_putstr("\t");
    ft_putnbr(ft_is_prime(2)); ft_putstr("\n");
    ft_putnbr(7); ft_putstr("\t");
    ft_putnbr(ft_is_prime(7)); ft_putstr("\n");
    ft_putnbr(19); ft_putstr("\t");
    ft_putnbr(ft_is_prime(19)); ft_putstr("\n");
    ft_putnbr(42); ft_putstr("\t");
    ft_putnbr(ft_is_prime(42)); ft_putstr("\n");
    ft_putnbr(783); ft_putstr("\t");
    ft_putnbr(ft_is_prime(783)); ft_putstr("\n");
    ft_putnbr(997); ft_putstr("\t");
    ft_putnbr(ft_is_prime(997)); ft_putstr("\n");

    return 0;
}