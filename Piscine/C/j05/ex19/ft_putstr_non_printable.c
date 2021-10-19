void ft_putchar(char);

void ft_putstr_non_printable(const char* str)
{
    char hexa[] = "0123456789abcdef";

    while (*str) {
        if (*str >= 32 && *str < 127)
            ft_putchar(*str);
        else {
            ft_putchar('\\');
            ft_putchar(hexa[*str >> 4]);
            ft_putchar(hexa[*str & 0x0f]);
        }
        ++str;
    }
}