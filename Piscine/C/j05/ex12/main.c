void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_str_is_printable(char const*);

int main()
{
    ft_putnbr(ft_str_is_printable("")); ft_putstr(" ");
    ft_putnbr(ft_str_is_printable("Hello, World!")); ft_putstr(" ");
    ft_putnbr(ft_str_is_printable("123xyz456")); ft_putstr(" ");
    ft_putnbr(ft_str_is_printable("abcdefg\n")); ft_putstr(" ");
    ft_putnbr(ft_str_is_printable("ABCDEFG")); ft_putstr(" ");

    return 0;
}