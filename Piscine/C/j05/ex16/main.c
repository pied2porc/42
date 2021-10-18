void         ft_putnbr(int);
void         ft_putstr(char const*);
unsigned int ft_strlcpy(char*, const char*, unsigned int);

int main()
{
    char str[13] = "Hello World!";
    ft_putnbr(ft_strlcpy(str, "Goodbye World!", 8));
    ft_putstr("\n"); ft_putstr(str); ft_putstr("\n");

    ft_putnbr(ft_strlcpy(str, "Goodbye World!", sizeof(str)));
    ft_putstr("\n"); ft_putstr(str); ft_putstr("\n");

    return 0;
}