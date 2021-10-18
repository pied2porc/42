void ft_putchar(char);

void ft_putstr(const char* str)
{
    while (str && *str != '\0') {
        ft_putchar(*str);
        ++str;
    }
}

int ft_pow(int n, int p)
{
    int res = n;
    while (--p > 0)
        res *= n;
    return res;
}

int ft_printNb(int nb, int n)
{
    if (n > 9) return 0;

    char res[10];
    int  eol = n;
    while(--n >= 0){
        res[n] = nb % 10;
        nb /= 10;
        if (n < (eol - 1) && res[n] >= res[n + 1])
            return 0;
    }
    while (++n < eol)
        ft_putchar('0' + res[n]);

    return 1;
}

void ft_print_combn(int n)
{
    if (n <= 0 || n >= 10) return;

    int max = ft_pow(10, n);
    for (int nb = 0; nb < max; ++nb)
        if (ft_printNb(nb, n))
            ft_putstr(", ");
    ft_putstr("\b\b \b");
}