#include "bistromathique.h"

/**
 * Adjust the quotient digit when the partial remainder is negative
 * by subtracting 1 from the quotient and adding a divisor to the
 * partial remainder to make it positive.
 */
void add_back(t_division*d, int base_len)
{
    d->qhat -= 1;
    d->lhs_norm.sign = PLUS_SIGN;
    int carry = 0;
    char* lpos = d->lhs_norm.value + (d->rhs_norm.end - d->rhs_norm.value);
    char* rpos = d->rhs_norm.end - 1;
    while (rpos >= d->rhs_norm.value) {
        int sum = *lpos + *rpos + carry;
        *lpos = (char)(sum % base_len);
        carry = sum / base_len;
        --rpos; --lpos;
    }
    *lpos = (char)((*lpos + carry) % base_len);
}

/**
 * Compute the partial remainder in place by multiplying the whole divisor by
 * the quotient digit and then subtracting from part of the numerator.
 */
void mul_sub(t_division* d, int base_len)
{
    int   carry = 0;
    int   borrow = 0;
    char* lpos = d->lhs_norm.value + (d->rhs_norm.end - d->rhs_norm.value);
    char* rpos = d->rhs_norm.end - 1;
    while (rpos >= d->rhs_norm.value) {
        int product = *(rpos) * d->qhat + carry;
        int diff = *lpos - product % base_len - borrow;
        carry = product / base_len;
        borrow = 0;
        if (diff < 0) {
            diff += base_len;
            borrow = 1;
        }
        *lpos = (char)diff;
        --rpos; --lpos;
    }
    *lpos -= (char)(carry + borrow);
    if (*lpos < 0) {
        *lpos += (char)base_len;
        d->lhs_norm.sign = MINUS_SIGN;
    }
}

void estimate_quotient(t_division* d, int base_len)
{
    d->n = d->lhs_norm.value[0] * base_len + d->lhs_norm.value[1];
    d->qhat = d->n / d->d;
    d->rhat = d->n % d->d;
    if (d->qhat == base_len ||
        d->qhat * d->rhs_norm.value[1] > d->rhat * base_len + d->lhs_norm.value[2]) {
        d->qhat -= 1;
        d->rhat += d->d;
        if (d->rhat < base_len &&
            d->qhat * d->rhs_norm.value[1] > d->rhat * base_len + d->lhs_norm.value[2]) {
            d->qhat -= 1;
            d->rhat += d->d;
        }
    }
}

/**
 * Multiplication with a single-digit multiplier
 */
t_number* short_mul(t_number* lhs, int m, t_number* result, int base_len)
{
    if (!*(lhs->value) || !m) {
        setNumberToZero(result);
        return result;
    }
    char* lpos = lhs->end - 1;
    int   carry = 0;
    result->value = result->end - 1;
    while (lpos >= lhs->value) {
        int product = *lpos * m + carry;
        *(result->value) = (char)(product % base_len);
        carry = product / base_len;
        --lpos; --result->value;
    }
    *(result->value) = (char)carry;
    result->value += 1 * !*(result->value);
    return result;
}

/**
 * Division with a single-digit divisor
 */
t_number* short_div(t_number* lhs, int d, t_number* result, int base_len)
{
    if (!d) {
        ft_putstr(DIV_BY_ZERO, CERR);
        return NULL;
    }
    char* lpos = lhs->value;
    int   r = 0;
    while (lpos < lhs->end) {
        int n = r * base_len + *lpos;
        *(result->value) = (char)(n / d);
        r = n % d;
        ++lpos; ++result->value;
    }
    result->end = result->value;
    skip_leading_zeros(result, result->begin);
    return result;
}