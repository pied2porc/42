#include "bistromathique.h"

/**
 * Addition:    A + B = C
 *              (-A) + (-B) = -(A + B) = (-C)
 * Subtraction: A + (-B) = A - (+B) = +/-C
 *              (-A) + B = B - A = +/-C
 */
t_number* sub_redirection(t_number* lhs, t_number* rhs, t_number* result, int base_len)
{
    if (lhs->sign != rhs->sign) {
        if (lhs->sign == MINUS_SIGN) {
            lhs->sign = PLUS_SIGN;
            return inf_sub(rhs, lhs, result, base_len);
        }
        else {
            rhs->sign = PLUS_SIGN;
            return inf_sub(lhs, rhs, result, base_len);
        }
    }
    return NULL;
}

/**
 * Grade-school addition
 */
t_number* inf_add(t_number* lhs, t_number* rhs, t_number* result, int base_len)
{
    if (sub_redirection(lhs, rhs, result, base_len) != NULL) return result;
    if (lhs->end - lhs->value < rhs->end - rhs->value) swapNumber(&lhs, &rhs);
    size_t pos = 1;
    int    carry = 0;
    while (rhs->value + pos <= rhs->end) {
        int sum = *(lhs->end - pos) + *(rhs->end - pos) + carry;
        carry = sum / base_len;
        *(result->end - pos) = (char)(sum % base_len);
        ++pos;
    }
    while (lhs->value + pos <= lhs->end) {
        int sum = *(lhs->end - pos) + carry;
        carry = sum / base_len;
        *(result->end - pos) = (char)(sum % base_len);
        ++pos;
    }
    *(result->end - pos) = (char)carry;
    result->value = result->end - pos + !carry;
    if (lhs->sign == MINUS_SIGN)
        result->sign = MINUS_SIGN;
    return result;
}