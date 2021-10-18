#include <io.h>

void ft_putaddr(void const* addr)
{
    static char const* hexa = "0123456789ABCDEF";
    unsigned int uiptr = (unsigned int)addr;

    int nibbles = sizeof(uiptr) * 2;
    while (--nibbles >= 0)
        _write(1, &hexa[uiptr >> (4 * nibbles) & 0xf], 1);
}