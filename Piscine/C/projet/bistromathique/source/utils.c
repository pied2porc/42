#include "bistromathique.h"
#include <io.h>
#include <stdlib.h>

/**
 * @return the index of the character contained in a string.
 * Return -1 if the character is not in the string.
 */
int ft_contains(char const* s, char c)
{
    int pos = 0;
    while (s[pos] && s[pos] != c) ++pos;
    return !s[pos] ? -1 : pos;
}

void ft_putnbr(int nb)
{
    if (nb < 0 && nb > -10)
        _write(1, "-", 1);
    if (nb >= 10 || nb <= -10)
        ft_putnbr(nb / 10);
    nb %= 10;
    nb = (nb < 0 ? -nb : nb) + '0';
    _write(1, &nb, 1);
}

void ft_putstr(char const* str, int fd)
{
    if (str)
        _write(fd, str, ft_strlen(str));
}

size_t ft_strlen(char const* str)
{
    if (!str) return 0;
    size_t pos = 0;
    while (str[pos]) ++pos;
    return pos;
}

int ft_strncmp(char* a, char* b, size_t n)
{
    size_t pos = 0;
    while (pos + 1 < n && a[pos] == b[pos])
        ++pos;
    return a[pos] - b[pos];
}

char* ft_strncpy(char const* s, size_t n)
{
    char* cpy = malloc(n);
    if (!cpy) {
        ft_putstr(MALLOC_ERR, CERR);
        return NULL;
    }
    size_t pos = 0;
    while (pos < n) {
        cpy[pos] = s[pos];
        ++pos;
    }
    return cpy;
}

unsigned int ft_uatoi(char* nb)
{
    unsigned int res;
    res = 0;
    while (*nb) {
        res = *nb - '0' + res * 10;
        nb = nb + 1;
    }
    return (res);
}