void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_str_is_uppercase(char const*);

int main()
{
    ft_putnbr(ft_str_is_uppercase("")); ft_putstr(" ");
    ft_putnbr(ft_str_is_uppercase("Hello, World!")); ft_putstr(" ");
    ft_putnbr(ft_str_is_uppercase("123xyz456")); ft_putstr(" ");
    ft_putnbr(ft_str_is_uppercase("abcdefg")); ft_putstr(" ");
    ft_putnbr(ft_str_is_uppercase("ABCDEFG")); ft_putstr(" ");

    return 0;
}