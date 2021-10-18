#include "bistromathique.h"

void skip_leading_zeros(t_number* nb, char* begin)
{
    nb->value = begin;
    while (nb->value < nb->end - 1 && *nb->value == 0)
        ++nb->value;
}

void setNumberToZero(t_number* nb)
{
    *(nb->end - 1) = 0;
    nb->value = nb->end - 1;
    nb->sign = PLUS_SIGN;
}