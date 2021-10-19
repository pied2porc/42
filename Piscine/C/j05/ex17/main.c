#include <limits.h>

void ft_putchar(char);
void ft_putnbr_base(int, char const*);

int main()
{
    ft_putnbr_base(42, "");
    ft_putnbr_base(42, "a+");
    ft_putnbr_base(42, "a-");
    ft_putnbr_base(42, "marcopolo");

    ft_putnbr_base(42, "0123456789");
    ft_putnbr_base(-123, "0123456789");
    ft_putnbr_base(INT_MAX, "0123456789");
    ft_putnbr_base(INT_MIN, "0123456789"); ft_putchar('\n');

    ft_putnbr_base(42, "01");
    ft_putnbr_base(-123, "01");
    ft_putnbr_base(INT_MAX, "01");
    ft_putnbr_base(INT_MIN, "01"); ft_putchar('\n');

    ft_putnbr_base(42, "0123456789ABCDEF");
    ft_putnbr_base(-123, "0123456789ABCDEF");
    ft_putnbr_base(INT_MAX, "0123456789ABCDEF");
    ft_putnbr_base(INT_MIN, "0123456789ABCDEF"); ft_putchar('\n');

    ft_putnbr_base(42, "poneyvif");
    ft_putnbr_base(-123, "poneyvif");
    ft_putnbr_base(INT_MAX, "poneyvif");
    ft_putnbr_base(INT_MIN, "poneyvif");

    return 0;
}