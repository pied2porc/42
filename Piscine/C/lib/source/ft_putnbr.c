#include <io.h>

void ft_putnbr(int nb) {
    if (nb < 0 && nb > -10)
        _write(1, "-", 1);
    if (nb >= 10 || nb <= -10)
        ft_putnbr(nb / 10);
    nb %= 10;
    nb = (nb < 0 ? -nb : nb) + '0';
    _write(1, &nb, 1);
}

void ft_putnbr_itr(int nb) {
    if (nb < 0)
        _write(1, "-", 1);

    // Count the number of digits
    int digits = (nb == 0 ? 1 : 0);
    for (int tmp = nb; tmp; ++digits)
        tmp /= 10;

    // Unwind the digits starting from the left most digit
    while (--digits >= 0) {
        int tmp = nb;
        for (int i = 0; i < digits; ++i)
            tmp /= 10;

        tmp %= 10;
        tmp = (tmp < 0 ? -tmp : tmp) + '0';
        _write(1, (char*)(&tmp), 1);
    }
}