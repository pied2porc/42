
void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_atoi(const char *);

int main()
{
    ft_putnbr(ft_atoi("+-+--+0123456789fhdskjlfhq")); ft_putstr("\n");
    ft_putnbr(ft_atoi(" -123junk")); ft_putstr("\n");
    ft_putnbr(ft_atoi("0")); ft_putstr("\n");
    ft_putnbr(ft_atoi("junk")); ft_putstr("\n");
    ft_putnbr(ft_atoi("2147483648")); ft_putstr("\n"); // int overflow
    ft_putnbr(ft_atoi("3.14159")); ft_putstr("\n");
    ft_putnbr(ft_atoi("31337 with words")); ft_putstr("\n");
    ft_putnbr(ft_atoi("words and 2")); ft_putstr("\n");

    return 0;
}