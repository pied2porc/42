#include <io.h>

void ft_putchar(char c) {
    _write(1, &c, 1);
}