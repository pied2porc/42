#include "bistromathique.h"
#include <io.h>

void printStackReverse(t_node* stack, t_expr* expr)
{
    if (!stack) return;
    stack = stack->tail;
    while (stack) {
        if (stack->token.op >= 0)
            _write(COUT, &(expr->ops[stack->token.op]), 1);
        else
            printNumberString(&(stack->token.nb), expr->base, expr->ops, TRUE);
        stack = stack->prev;
        if (stack)
            _write(COUT, " ", 1);
    }
}

/**
 * Print a number in its character form.
 */
void printNumberString(t_number* nb, char const* base, char const* ops, int skipLeadingZeros)
{
    if (!nb || !nb->value) return;
    if (nb->sign == MINUS_SIGN)
        _write(COUT, &ops[op_minus], 1);
    char* begin = skipLeadingZeros ? nb->value : nb->begin;
    size_t size = nb->end - begin;
    char* cpy = ft_strncpy(begin, size);
    valueToDigit(cpy, cpy + size, base);
    _write(COUT, cpy, size);
    free(cpy);
}

/**
 * Print a number in its numerical form.
 */
void printNumberValue(t_number* nb,  char const* separator, char const* ops, int skipLeadingZeros)
{
    if (!nb || !nb->value) return;
    if (nb->sign < 0)
        _write(COUT, &ops[op_minus], 1);
    int separator_len = ft_strlen(separator);
    char* pos = skipLeadingZeros ? nb->value : nb->begin;
    while (pos < nb->end) {
        ft_putnbr(*pos);
        ++pos;
        _write(COUT, separator, separator_len * (pos < nb->end));
    }
}