#include "bistromathique.h"

int getPrecedence(int op)
{
    switch (op) {
    case op_plus:
    case op_minus: return 1;
    case op_mul:
    case op_div:
    case op_mod: return 2;
    default: return 0;
    }
}

int transferRemainingOperators(t_node** ops, t_node** postfix)
{
    while (*ops) {
        if ((*ops)->token.type == tt_parOpen) {
            ft_putstr(PAREN_ERR, CERR);
            return EXIT_FAILURE;
        }
        transferNode(ops, postfix);
    }
    return EXIT_SUCCESS;
}