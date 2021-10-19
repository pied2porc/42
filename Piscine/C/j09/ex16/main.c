void         ft_putbit(long long, int);
void         ft_putnbr(int);
void         ft_putstr(char const*);
unsigned int ft_active_bits(int);

int main()
{
    ft_putbit(42, sizeof(int) * 8); ft_putstr(" ");
    ft_putnbr(ft_active_bits(42)); ft_putstr("\n");

    ft_putbit(-42, sizeof(int) * 8); ft_putstr(" ");
    ft_putnbr(ft_active_bits(-42)); ft_putstr("\n");

    ft_putbit(123456789, sizeof(int) * 8); ft_putstr(" ");
    ft_putnbr(ft_active_bits(123456789)); ft_putstr("\n");

    return 0;
}