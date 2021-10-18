void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_str_is_numeric(char const*);

int main()
{
    ft_putnbr(ft_str_is_numeric("")); ft_putstr(" ");
    ft_putnbr(ft_str_is_numeric("Hello, World!")); ft_putstr(" ");
    ft_putnbr(ft_str_is_numeric("123xyz456")); ft_putstr(" ");
    ft_putnbr(ft_str_is_numeric("123465")); ft_putstr(" ");

    return 0;
}