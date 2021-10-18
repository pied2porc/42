#include <limits.h>

void ft_putchar(char);
void ft_putnbr(int);

int main()
{
    ft_putnbr(0);       ft_putchar(' ');
    ft_putnbr(1);       ft_putchar(' ');
    ft_putnbr(-1);      ft_putchar(' ');
    ft_putnbr(1024);    ft_putchar(' ');
    ft_putnbr(-256);    ft_putchar(' ');
    ft_putnbr(INT_MAX); ft_putchar(' ');
    ft_putnbr(INT_MIN); ft_putchar(' ');

    return 0;
}