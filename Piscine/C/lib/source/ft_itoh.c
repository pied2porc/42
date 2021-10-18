#include <io.h>

char* ft_itoh(unsigned int i, char* s, int digits)
{
    static char const hexa[] = "0123456789abcdef";
    char* const s_begin = s;
    int         nibbles = sizeof(i) * 2;
    if (digits <= 0) digits = 1;
    nibbles = digits < nibbles ? digits : nibbles;

    while (--nibbles >= 0) {
        *s = hexa[i >> (4 * nibbles) & 0xf];
        ++s;
    }
    *s = 0;
    return s_begin;
}
