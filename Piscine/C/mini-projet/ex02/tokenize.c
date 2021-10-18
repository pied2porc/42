#include "eval_expr.h"
#include "eval_utils.h"
#include "ft.h"
#include "stack.h"
#include "tokenize.h"
#include "transfer_token.h"
#include <stdlib.h>

e_tokenType pushTerm(char** expr, t_token** operators, t_token** postfix,
                     e_tokenType lastToken)
{
    // syntax error: operator missing between terms
    if (lastToken != tt_none && (lastToken == tt_term || lastToken == tt_parClose))
        cleanup_n_die(SYNTAX_ERR_MSG, operators, postfix);
    int term = ft_atoi(*expr);
    if (*postfix && (*postfix)->tt == tt_sign) {
        (*postfix)->nb *= term;
        (*postfix)->tt = tt_term;
    }
    else {
        t_token t = { term, '\0', tt_term, NULL };
        push(&t, postfix);
    }
    while (**expr >= '0' && **expr <= '9')
        ++(*expr);
    return tt_term;
}

e_tokenType pushParenthesis(char** expr, t_token** operators, t_token** postfix,
                            e_tokenType lastToken)
{
    // syntax error: operator missing before an open parenthesis
    if (lastToken != tt_none && (lastToken == tt_term || lastToken == tt_parClose))
        cleanup_n_die(SYNTAX_ERR_MSG, operators, postfix);
    // add a multiplication by -1 if there's a negative sign before the parenthesis
    if (*postfix && (*postfix)->tt == tt_sign && (*postfix)->nb < 0) {
        (*postfix)->tt = tt_term;
        t_token t = { 0, '*', tt_operator, NULL };
        push(&t, operators);
    }
    t_token t = { 0, '(', tt_parOpen, NULL };
    push(&t, operators);
    ++(*expr);
    return tt_parOpen;
}

e_tokenType popParenthesis(char** expr, t_token** operators, t_token** postfix,
                           e_tokenType lastToken)
{
    // syntax error: operand missing before a close parenthesis
    if (lastToken != tt_term && lastToken != tt_parClose)
        cleanup_n_die(SYNTAX_ERR_MSG, operators, postfix);
    while (*operators && (*operators)->op != '(')
        transferToken(operators, postfix);
    if (!*operators)
        cleanup_n_die(PAREN_ERR_MSG, operators, postfix);
    pop(operators);
    ++(*expr);
    return tt_parClose;
}

e_tokenType pushOperator(char** expr, t_token** operators, t_token** postfix,
                         e_tokenType lastToken)
{
    if (**expr == '*' || **expr == '/' || **expr == '%') {
        // syntax error: operand missing
        if (lastToken != tt_term && lastToken != tt_parClose)
            cleanup_n_die(SYNTAX_ERR_MSG, operators, postfix);
        transferOperators(**expr, operators, postfix);
        ++(*expr);
    }
    else if (**expr == '+' || **expr == '-') {
        int sign = getSign(expr);
        char op = sign > 0 ? '+' : '-';
        if (lastToken == tt_term || lastToken == tt_parClose)
            transferOperators(op, operators, postfix);
        else {
            t_token t = { sign, '\0', tt_sign, NULL };
            push(&t, postfix);
            return tt_sign;
        }
    }
    return tt_operator;
}