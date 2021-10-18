#include "bistromathique.h"

t_number* do_op(int op, t_number* lhs, t_number* rhs, t_number* result, t_expr* expr)
{
    t_number* (*op_fnc[5])(t_number* lhs, t_number* rhs, t_number* result, int base_len)
                        = { inf_add, inf_sub, inf_mul, inf_div, inf_mod };
    size_t res_size = MAX(lhs->end - lhs->value, rhs->end - rhs->value);
    if (op == op_minus || op == op_mod)
        res_size = MAX(lhs->end - lhs->value, rhs->end - rhs->value);
    else if (op == op_plus)
        res_size = MAX(lhs->end - lhs->value, rhs->end - rhs->value) + 1;
    else if (op == op_mul)
        res_size = (lhs->end - lhs->value) + (rhs->end - rhs->value);
    else if (op == op_div)
        res_size = MAX((lhs->end - lhs->value) - (rhs->end - rhs->value) + 2, 1);
    if (initNumber(result, NULL, res_size, PLUS_SIGN) == EXIT_FAILURE)
        return NULL;
    op_fnc[op - 2](lhs, rhs, result, expr->base_len);
    return result;
}

t_number* eval_postfix(t_node** postfix, t_number* result, t_expr* expr)
{
    if (!*postfix) return NULL;
    *postfix = (*postfix)->tail;
    while (*postfix) {
        if ((*postfix)->token.type == tt_operator) {
            int op = (*postfix)->token.op;
            removeNode(postfix); // free op
            t_number* rhs = &(*postfix)->token.nb;
            t_number* lhs = &((*postfix)->next->token.nb);
            if (do_op(op, lhs, rhs, result, expr) == NULL)
                return NULL;
            removeNode(postfix); // free rhs
            (*postfix)->token.nb = *result; // store result in lhs
        }
        if (!(*postfix)->prev) break;
        *postfix = (*postfix)->prev;
    }
    return &(*postfix)->token.nb;
}

t_number eval_expr(t_expr* expr)
{
    t_node*  postfix = toPostfix(expr);
    t_number result = { 0 };
    eval_postfix(&postfix, &result, expr);
    free(postfix);
    return result;
}