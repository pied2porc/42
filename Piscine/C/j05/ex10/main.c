void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_str_is_lowercase(char const*);

int main()
{
    ft_putnbr(ft_str_is_lowercase("")); ft_putstr(" ");
    ft_putnbr(ft_str_is_lowercase("Hello, World!")); ft_putstr(" ");
    ft_putnbr(ft_str_is_lowercase("123xyz456")); ft_putstr(" ");
    ft_putnbr(ft_str_is_lowercase("123465")); ft_putstr(" ");
    ft_putnbr(ft_str_is_lowercase("abcdefg")); ft_putstr(" ");

    return 0;
}