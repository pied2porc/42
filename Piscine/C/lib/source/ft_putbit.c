#include <io.h>

void ft_putbit(long long data, int size)
{
    while (--size >= 0) {
        char c = !(data >> size & 1) ? '0' : '1';
        _write(1, &c, 1);
        if (size && !(size % 8))
            _write(1, "'", 1);
    }
}