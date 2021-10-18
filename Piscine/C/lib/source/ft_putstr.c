#include <io.h>

void ft_putstr(char const* str)
{
    if (!str) return;

    int i = -1;
    while (str[++i]);
    _write(1, str, i);
}