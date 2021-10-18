void ft_putnbr(int);
void ft_putstr(char const*);
unsigned int ft_strlcat(char*, char const*, unsigned int);
#include <string.h>

int main()
{
    char str[20] = "Hello World!";
    ft_putnbr(ft_strlcat(str, " Goodbye World!", sizeof(str)));
    ft_putstr("\n");
    ft_putstr(str);

    return 0;
}