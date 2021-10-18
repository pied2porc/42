void  ft_putstr(char const*);
char* ft_convert_base(char const*, char const*, char const*);

int main()
{
    ft_putstr(ft_convert_base("-abcfff", "0123456789abcdef", "0123456789"));
    ft_putstr("\n");
    ft_putstr(ft_convert_base("-11259903", "0123456789", "0123456789abcdef"));
    ft_putstr("\n");
    ft_putstr(ft_convert_base("7fffffff", "0123456789abcdef", "0123456789"));
    ft_putstr("\n");
    ft_putstr(ft_convert_base("2147483647", "0123456789", "0123456789abcdef"));
    ft_putstr("\n");
    ft_putstr(ft_convert_base("2147483647", "0123456789", "01"));
    ft_putstr("\n");
    ft_putstr(ft_convert_base("-2147483648", "0123456789", "01"));
    ft_putstr("\n");
    ft_putstr(ft_convert_base("-2147483649", "0123456789", "01"));
    ft_putstr("\n");

    return 0;
}