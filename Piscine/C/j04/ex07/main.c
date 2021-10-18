void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_find_next_prime(int);

int main()
{
    ft_putnbr(ft_find_next_prime(0)); ft_putstr("\n");
    ft_putnbr(ft_find_next_prime(1)); ft_putstr("\n");
    ft_putnbr(ft_find_next_prime(2)); ft_putstr("\n");
    ft_putnbr(ft_find_next_prime(42)); ft_putstr("\n");
    ft_putnbr(ft_find_next_prime(783)); ft_putstr("\n");
    ft_putnbr(ft_find_next_prime(991)); ft_putstr("\n");
    ft_putnbr(ft_find_next_prime(997)); ft_putstr("\n");

    return 0;
}