void ft_putchar(char);

int containsChar(char const* str, char c)
{
    while (*str != '\0') {
        if (*str == c)
            return 1;
        ++str;
    }
    return 0;
}

int containsDup(char const* str)
{
    while (*str != '\0') {
        if (containsChar(str + 1, *str))
            return 1;
        ++str;
    }
    return 0;
}

int baseLen(char const* base)
{
    char const* cur = base;
    while (*cur != '\0')
        ++cur;
    return cur - base;
}

int isValidBase(char const* base, int len)
{
    if (len <= 1 || containsChar(base, '+') || containsChar(base, '-') ||
        containsDup(base))
        return 0;
    return 1;
}

void putnbr_base_rec(int nbr, char const* base, int len)
{
    if (nbr >= len || nbr <= -len)
        putnbr_base_rec(nbr / len, base, len);
    if (nbr < 0)
        ft_putchar(base[-(nbr % len)]);
    else
        ft_putchar(base[nbr % len]);
}

void ft_putnbr_base(int nbr, char const* base)
{
    int len = baseLen(base);
    if (!isValidBase(base, len))
        return;
    if (nbr < 0)
        ft_putchar('-');
    putnbr_base_rec(nbr, base, len);
    ft_putchar('\n');
}