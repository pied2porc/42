#include "bistromathique.h"

t_number* inf_mod(t_number* lhs, t_number* rhs, t_number* result, int base_len)
{
    t_number q; // quotient
    t_number p; // product
    if (initNumber(&q, NULL, lhs->end - lhs->value,
                   lhs->sign * rhs->sign) == EXIT_FAILURE)
        return NULL;
    if (inf_div(lhs, rhs, &q, base_len) == NULL ||
        initNumber(&p, NULL, (q.end - q.value) + (rhs->end - rhs->value),
                   q.sign * rhs->sign) == EXIT_FAILURE) {
        freeNumber(&q);
        return NULL;
    }
    inf_mul(&q, rhs, &p, base_len);
    // result must hold enough memory to perfom the subtraction
    inf_sub(lhs, &p, result, base_len);
    freeNumber(&q);
    freeNumber(&p);
    return result;
}