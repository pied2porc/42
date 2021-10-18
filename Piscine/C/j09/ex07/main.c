void         ft_putchar(char);
void         ft_putnbr(int);
unsigned int ft_collatz_conjecture(unsigned int);

int main()
{
    ft_putnbr(ft_collatz_conjecture(15)); ft_putchar(' ');
    ft_putnbr(ft_collatz_conjecture(127)); ft_putchar('\n');
    return 0;
}