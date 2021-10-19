#include <stdlib.h>
#include <limits.h>

void ft_putstr(char const*);

int ft_strlen(char const* str)
{
    char const* end = str;
    while (*end)
        ++end;
    return end - str;
}

int ft_getnbr_base(char const* nbr, char const* base, int base_len)
{
    int sign = 1;
    while (*nbr == '+' || *nbr == '-') {
        if (*nbr == '-')
            sign = -sign;
        ++nbr;
    }

    long long res = 0;
    while (*nbr) {
        int pos = 0;
        while (base[pos] && base[pos] != *nbr)
            ++pos;
        res = res * base_len + pos;
        if (sign > 0 && res > INT_MAX || sign < 0 && -res < INT_MIN) {
            ft_putstr("int overflow.\n");
            exit (1);
        }
        ++nbr;
    }
    return (int)res * sign;
}

char* ft_getstr_base(int nbr, char const* base, int base_len)
{
    // +2 bytes for the null character and a potential minus sign.
    char* res = malloc(sizeof(int) * 8 + 2);
    if (!res)
        return 0;
    int nbr_cpy = nbr;
    int pos = sizeof(int) * 8 + 1;
    res[pos] = 0;
    while (nbr) {
        res[--pos] =
            (nbr < 0) ? base[(-(nbr % base_len))] : base[(nbr % base_len)];
        nbr /= base_len;
    }
    if (nbr_cpy < 0)
        res[--pos] = '-';
    return res + pos;
}

char* ft_convert_base(char const* nbr, char const* base_from, char const* base_to)
{
    int dec = ft_getnbr_base(nbr, base_from, ft_strlen(base_from));
    return ft_getstr_base(dec, base_to, ft_strlen(base_to));
}