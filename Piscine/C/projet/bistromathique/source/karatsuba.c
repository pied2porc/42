#include "bistromathique.h"
#include <assert.h>
#include <stdlib.h>

void freeKaratsuba(t_karatsuba* k)
{
    if (!k) return;
    if (&k->sum[0].begin)
        free(k->sum[0].begin);
    if (&k->sum[1].begin)
        free(k->sum[1].begin);
    if (&k->product[0].begin)
        free(k->product[0].begin);
    if (&k->product[1].begin)
        free(k->product[1].begin);
    if (&k->product[2].begin)
        free(k->product[2].begin);
}

int initKaratsuba(t_karatsuba *k)
{
    if (initNumber( &k->sum[0], NULL, MAX(k->x[0].end - k->x[0].value,
                    k->x[1].end - k->x[1].value) + 1, PLUS_SIGN) == EXIT_FAILURE ||
        initNumber( &k->sum[1], NULL, MAX(k->y[0].end - k->y[0].value,
                    k->y[1].end - k->y[1].value) + 1, PLUS_SIGN) == EXIT_FAILURE ||
        initNumber( &k->product[0], NULL, (k->x[0].end - k->x[0].value) +
                    (k->y[0].end - k->y[0].value), PLUS_SIGN) == EXIT_FAILURE ||
        initNumber( &k->product[1], NULL, (k->x[1].end - k->x[1].value) +
                    (k->y[1].end - k->y[1].value), PLUS_SIGN) == EXIT_FAILURE ||
        initNumber( &k->product[2], NULL, (k->sum[0].end - k->sum[0].value) +
                    (k->sum[1].end - k->sum[1].value), PLUS_SIGN) == EXIT_FAILURE) {
        freeKaratsuba(k);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void splitNumber(t_number* nb, t_number parts[2], size_t half)
{
    parts[1].sign = PLUS_SIGN;
    parts[0].sign = PLUS_SIGN;
    parts[1].pointsToBuffer = TRUE;
    parts[0].pointsToBuffer = TRUE;
    // Split number from the right most digit
    parts[1].end = nb->end;
    if (half && nb->end - half > nb->value) {
        parts[1].begin = nb->end - half;
        parts[1].value = parts[1].begin;
        skip_leading_zeros(&parts[1], parts[1].begin);
        parts[0].end   = parts[1].begin;
        parts[0].begin = nb->begin;
        parts[0].value = nb->value;
    }
    else {
        parts[1].begin = nb->begin;
        parts[1].value = nb->value;
        parts[0].begin = "\x0";
        parts[0].end   = parts[0].begin + 1;
        parts[0].value = parts[0].begin;
    }
}

t_number* karatsuba(t_number* lhs, t_number* rhs, t_number* result, int base_len)
{
    size_t half = MAX(lhs->end - lhs->value, rhs->end - rhs->value) / 2;
    t_karatsuba k;
    splitNumber(lhs, k.x, half);
    splitNumber(rhs, k.y, half);
    if (initKaratsuba(&k) == EXIT_FAILURE)
        return NULL;
    inf_mul(&k.x[0], &k.y[0], &k.product[0], base_len);
    inf_mul(&k.x[1], &k.y[1], &k.product[1], base_len);
    inf_add(&k.x[0], &k.x[1], &k.sum[0], base_len);
    inf_add(&k.y[0], &k.y[1], &k.sum[1], base_len);
    inf_mul(&k.sum[0], &k.sum[1], &k.product[2], base_len);
    inf_sub(&k.product[2], &k.product[0], &k.product[2], base_len);
    inf_sub(&k.product[2], &k.product[1], &k.product[2], base_len);
    add_term_to(&k.product[0], result, half * 2, base_len);
    add_term_to(&k.product[1], result, 0, base_len);
    add_term_to(&k.product[2], result, half, base_len);
    freeKaratsuba(&k);
    return result;
}