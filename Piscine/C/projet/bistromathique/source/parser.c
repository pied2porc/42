#include "bistromathique.h"

e_tokenType parseSign(t_expr* expr, t_node** ops, t_node** postfix, e_tokenType lastTokenType)
{
    // A +/- operator must come after a number or a close parenthesis.
    if (lastTokenType == tt_number || lastTokenType == tt_parClose) {
        int op = *(expr->buffer) == expr->ops[op_plus] ? op_plus : op_minus;
        return pushOperator(op, expr, ops, postfix, lastTokenType);
    }
    // Otherwise it's a sign.
    int sign = PLUS_SIGN;
    while (*(expr->buffer) == expr->ops[op_plus] ||
           *(expr->buffer) == expr->ops[op_minus]) {
        if (*(expr->buffer) == expr->ops[op_minus])
            sign *= -1;
        ++expr->buffer;
    }
    return sign == PLUS_SIGN ? tt_plusSign : tt_minusSign;
}

#ifdef _BENCHMARK_TEST
/* Modify a copy of the buffer */
e_tokenType pushNumber(t_expr* expr, t_node** postfix, e_tokenType lastTokenType)
{
    char* end = expr->buffer;
    while (ft_contains(expr->base, *end) >= 0)
        ++end;
    size_t size = end - expr->buffer;
    char* begin = malloc(size);
    end = begin;
    while (end < begin + size) {
        *end = (char)getNumberValue(*expr->buffer, expr->base);
        ++expr->buffer;
        ++end;
    }
    push(newNode(op_none, tt_number), postfix);
    initNumber(&(*postfix)->token.nb, begin, size,
               lastTokenType == tt_minusSign ? MINUS_SIGN : PLUS_SIGN);
    skip_leading_zeros(&(*postfix)->token.nb, (*postfix)->token.nb.begin);
    (*postfix)->token.nb.pointsToBuffer = FALSE;
    return tt_number;
}
#else
/* Modify buffer in place */
e_tokenType pushNumber(t_expr* expr, t_node** postfix, e_tokenType lastTokenType)
{
    char* begin = expr->buffer;
    char* end = digitToValue(expr->buffer, expr->base, expr->base_len);
    push(newNode(op_none, tt_number), postfix);
    initNumber(&(*postfix)->token.nb, begin, end - begin,
               lastTokenType == tt_minusSign ? MINUS_SIGN : PLUS_SIGN);
    skip_leading_zeros(&(*postfix)->token.nb, (*postfix)->token.nb.begin);
    expr->buffer += end - begin;
    return tt_number;
}
#endif

e_tokenType pushParenthesis(t_expr* expr, t_node** ops, t_node** postfix, e_tokenType lastTokenType)
{
    // An open parenthesis must come after an operator.
    if (lastTokenType == tt_number || lastTokenType == tt_parClose) {
        ft_putstr(SYNTAX_ERR, CERR);
        return tt_err;
    }
    // Multiply by -1 if the parenthesis is preceded by a minus sign.
    if (lastTokenType == tt_minusSign) {
        push(newNode(op_mul, tt_operator), ops);
        push(newNode(op_none, tt_number), postfix);
        initNumber(&(*postfix)->token.nb, NULL, 1, MINUS_SIGN);
        (*postfix)->token.nb.begin[0] = 1;
    }
    push(newNode(op_parOpen, tt_parOpen), ops);
    ++expr->buffer;
    return tt_parOpen;
}

e_tokenType popParenthesis(t_expr* expr, t_node** ops, t_node** postfix, e_tokenType lastTokenType)
{
    // A close parenthesis must come after a number or another close parenthesis.
    if (lastTokenType != tt_number && lastTokenType != tt_parClose) {
        ft_putstr(SYNTAX_ERR, CERR);
        return tt_err;
    }
    while (*ops) {
        if ((*ops)->token.type == tt_parOpen)
            break;
        transferNode(ops, postfix);
    }
    if (!*ops) {
        ft_putstr(PAREN_ERR, CERR);
        return tt_err;
    }
    pop(ops);
    ++expr->buffer;
    return tt_parClose;
}

e_tokenType pushOperator(int op, t_expr* expr, t_node** ops, t_node** postfix, e_tokenType lastTokenType)
{
    // An operator must come after a number or a close parenthesis.
    if (lastTokenType != tt_number && lastTokenType != tt_parClose) {
        ft_putstr(SYNTAX_ERR, CERR);
        return tt_err;
    }
    while (*ops) {
        if (getPrecedence((*ops)->token.op) < getPrecedence(op))
            break;
        transferNode(ops, postfix);
    }
    push(newNode(op, tt_operator), ops);
    ++expr->buffer;
    return tt_operator;
}

t_node* toPostfix(t_expr* expr)
{
    t_node* postfix = NULL;
    t_node* ops = NULL;
    e_tokenType lastTokenType = tt_none;
    int op = op_none;
    while (*(expr->buffer) && lastTokenType != tt_err) {
        if (*(expr->buffer) == expr->ops[op_plus] ||
            *(expr->buffer) == expr->ops[op_minus])
            lastTokenType = parseSign(expr, &ops, &postfix, lastTokenType);
        else if (ft_contains(expr->base, *(expr->buffer)) >= 0)
            lastTokenType = pushNumber(expr, &postfix, lastTokenType);
        else if (*(expr->buffer) == expr->ops[op_parOpen])
            lastTokenType = pushParenthesis(expr, &ops, &postfix, lastTokenType);
        else if (*(expr->buffer) == expr->ops[op_parClose])
            lastTokenType = popParenthesis(expr, &ops, &postfix, lastTokenType);
        else if ((op = ft_contains(expr->ops + 2, *(expr->buffer))) >= 0) // Skip the parenthesis
            lastTokenType = pushOperator(op + 2, expr, &ops, &postfix, lastTokenType);
        else
            lastTokenType = syntaxError();
    }
    if (lastTokenType != tt_number && lastTokenType != tt_parClose && lastTokenType != tt_err)
        lastTokenType = syntaxError();
    if (lastTokenType == tt_err ||
        transferRemainingOperators(&ops, &postfix) == EXIT_FAILURE)
        deleteStack(&postfix);
    deleteStack(&ops);
    return postfix;
}