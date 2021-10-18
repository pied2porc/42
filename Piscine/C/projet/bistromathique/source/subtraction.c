#include "bistromathique.h"

/**
 * Move the greatest number to lhs and adjust the result's sign accordingly.
 */
void reorder_terms(t_number** lhs, t_number** rhs, t_number* result)
{
    if (isSmallerThan(*lhs, *rhs)) {
        if ((*lhs)->sign == PLUS_SIGN)
            result->sign = MINUS_SIGN;
        swapNumber(lhs, rhs);
    }
    else if ((*lhs)->sign == MINUS_SIGN)
        result->sign = MINUS_SIGN;
}

/**
 * Subtraction: A - B = +/-C
 *              (-A) - (-B) = (-A) + B = B - A = +/-C
 * Addition:    A - (-B) = A + B = C
 *              (-A) - B = (-A) + (-B) = -(A + B) = (-C)
 */
t_number* add_redirection(t_number* lhs, t_number *rhs, t_number* result, int base_len)
{
    if (lhs->sign != rhs->sign) {
        rhs->sign = (lhs->sign == MINUS_SIGN ? MINUS_SIGN : PLUS_SIGN);
        return inf_add(lhs, rhs, result, base_len);
    }
    return NULL;
}

/**
 * Grade-school subtraction
 */
t_number* inf_sub(t_number* lhs, t_number* rhs, t_number* result, int base_len)
{
    if (add_redirection(lhs, rhs, result, base_len) != NULL) return result;
    reorder_terms(&lhs, &rhs, result);
    size_t pos = 1;
    int    carry = 0;
    while (rhs->value + pos <= rhs->end) {
        int diff = *(lhs->end - pos) - *(rhs->end - pos) - carry;
        carry = 0;
        if (diff < 0) {
            diff += base_len;
            carry = 1;
        }
        *(result->end - pos++) = (char)diff % base_len;
    }
    while (lhs->value + pos <= lhs->end) {
        int diff = *(lhs->end - pos) - carry;
        carry = 0;
        if (diff < 0) {
            diff += base_len;
            carry = 1;
        }
        *(result->end - pos++) = (char)diff % base_len;
    }
    skip_leading_zeros(result, result->end - pos + 1);
    if (!*result->value) result->sign = PLUS_SIGN;
    return result;
}