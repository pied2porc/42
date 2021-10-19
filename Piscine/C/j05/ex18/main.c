void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_atoi_base(char const*, char const*);

int main()
{
    ft_putnbr(ft_atoi_base("2A", "0123456789ABCDEF")); ft_putstr("\n");
    ft_putnbr(ft_atoi_base("AF", "0123456789ABCDEF"));

    return 0;
}