#include "bistromathique.h"

void freeDivision(t_division* d)
{
    if (!d) return;
    freeNumber(&d->lhs_norm);
    freeNumber(&d->rhs_norm);
    free(d);
}

t_division* initDivision(t_number* lhs, t_number* rhs, int base_len)
{
    t_division* d = NULL;
    if ((d = malloc(sizeof (*d))) == NULL) {
        ft_putstr(MALLOC_ERR, CERR);
        return NULL;
    }
    d->norm_factor = base_len / (rhs->value[0] + 1);
    // Add a char to the dividend to accommodate an additional leading zero digit.
    if (initNumber(&d->lhs_norm, NULL, (lhs->end - lhs->value) + 2, PLUS_SIGN)
        == EXIT_FAILURE ||
        initNumber(&d->rhs_norm, NULL, (rhs->end - rhs->value) + 1, PLUS_SIGN)
        == EXIT_FAILURE) {
        freeNumber(&d->lhs_norm);
        return NULL;
    }
    // Normalize the dividend and divisor.
    short_mul(lhs, d->norm_factor, &d->lhs_norm, base_len);
    short_mul(rhs, d->norm_factor, &d->rhs_norm, base_len);
    // Make sure to start the dividend on a leading zero.
    *(d->lhs_norm.begin) = 0;
    d->lhs_norm.value -= 1;

    d->d = d->rhs_norm.value[0];
    return d;
}

/**
 * Knuth's Algorithm D
 */
t_number* long_div(t_division* d, t_number* result, int base_len)
{
    char* end = d->lhs_norm.end - (d->rhs_norm.end - d->rhs_norm.value);
    while (d->lhs_norm.value < end) {
        estimate_quotient(d, base_len);
        mul_sub(d, base_len);
        if (d->lhs_norm.sign == MINUS_SIGN)
            add_back(d, base_len);
        *(result->value) = (char)d->qhat;
        ++result->value;
        ++d->lhs_norm.value;
    }
    result->end = result->value;
    skip_leading_zeros(result, result->begin);
    return result;
}

t_number* inf_div(t_number* lhs, t_number* rhs, t_number* result, int base_len)
{
    result->sign = lhs->sign * rhs->sign;
    if (isSmallerThan(lhs, rhs)) {
        setNumberToZero(result);
        return result;
    }
    if (rhs->end - rhs->value == 1) {
        short_div(lhs, *(rhs->value), result, base_len);
        return result;
    }
    t_division* d = initDivision(lhs, rhs, base_len);
    if (!d) return NULL;
    if (!long_div(d, result, base_len)) {
        freeDivision(d);
        return NULL;
    }
    freeDivision(d);
    return result;
}