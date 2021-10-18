#include "bistromathique.h"
#include <stdlib.h>

void add_term_to(t_number* term, t_number* result, size_t offset, int base_len)
{
    //assert(term->end - term->value + offset <= result->end - result->begin);
    int   carry = 0;
    char* res_pos = result->end - 1 - offset;
    char* term_pos = term->end - 1;
    while (term_pos >= term->value) {
        int sum = *term_pos + *res_pos + carry;
        carry = sum / base_len;
        *res_pos = (char)(sum % base_len);
        --term_pos; --res_pos;
    }
    while (carry && res_pos >= result->begin) {
        int sum = *res_pos + carry;
        carry = sum / base_len;
        *res_pos = (char)(sum % base_len);
        --res_pos;
    }
    skip_leading_zeros(result, result->begin);
}

t_number* long_mul(t_number* lhs, t_number* rhs, t_number* result, int base_len)
{
    char* lend = lhs->end;
    char* rend = rhs->end;
    t_multiplication m;
    m.lsize = lend - lhs->value;
    m.rsize = rend - rhs->value;
    m.res_size = result->end - result->begin;
    m.res_pos = m.res_size - 1;
    int product = 0;
    while (m.res_pos >= 0) {
        m.rpos = m.res_size - m.res_pos;
        m.lpos = 1;
        if (m.rpos > m.rsize) {
            m.lpos += (m.rpos - m.rsize);
            m.rpos -= (m.rpos - m.rsize);
        }
        while (m.lpos <= m.lsize && m.lpos <= m.res_size - m.res_pos)
            product += *(lend - m.lpos++) * *(rend - m.rpos--);
        result->begin[m.res_pos] = (char)(product % base_len);
        product /= base_len;
        --m.res_pos;
    }
    skip_leading_zeros(result, result->begin);
    return result;
}

t_number* inf_mul(t_number* lhs, t_number* rhs, t_number* result, int base_len)
{
    size_t lsize = lhs->end - lhs->value;
    size_t rsize = rhs->end - rhs->value;
    setStringToZero(result->begin, result->end);
    if (!*(lhs->value) || !*(rhs->value))
        setNumberToZero(result);
    else if (lsize + rsize < LONG_MUL_THRESHOLD || (lsize < 50 || rsize < 50))
        long_mul(lhs, rhs, result, base_len);
    else
        karatsuba(lhs, rhs, result, base_len);
    result->sign = lhs->sign * rhs->sign;
    return result;
}