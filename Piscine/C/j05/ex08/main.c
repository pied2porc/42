void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_str_is_alpha(char const*);

int main()
{
    ft_putnbr(ft_str_is_alpha("")); ft_putstr(" ");
    ft_putnbr(ft_str_is_alpha("Hello, World!")); ft_putstr(" ");
    ft_putnbr(ft_str_is_alpha("abc123xyz")); ft_putstr(" ");
    ft_putnbr(ft_str_is_alpha("abcdefXYZ")); ft_putstr(" ");

    return 0;
}