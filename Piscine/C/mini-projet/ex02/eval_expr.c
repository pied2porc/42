#include "eval_expr.h"
#include "eval_utils.h"
#include "ft.h"
#include "parser.h"
#include "stack.h"
#include "tokenize.h"
#include "transfer_token.h"
#include <stdlib.h>

void printPostfix(t_token* postfix)
{
    postfix = postfix->tail;
    while (postfix) {
        !postfix->op ? ft_putnbr(postfix->nb) : ft_putchar(postfix->op);
        ft_putchar(' ');
        postfix = postfix->prev;
    }
    ft_putchar('\n');
}

/**
 * Convert an infix expression to a tokenized postfix notation using 
 * a bidirectional stack.
 * @var: lastToken-- helps distinguish between the +/- sign and the +/- operator
 *       and used to detect most syntax errors.
 */
t_token* toPostfix(char* expr)
{
    t_token*    postfix = NULL;
    t_token*    operators = NULL;
    e_tokenType lastToken = tt_none;

    while (*expr) {
        if (*expr >= '0' && *expr <= '9')
            lastToken = pushTerm(&expr, &operators, &postfix, lastToken);
        else if (*expr == '(')
            lastToken = pushParenthesis(&expr, &operators, &postfix, lastToken);
        else if (*expr == ')')
            lastToken = popParenthesis(&expr, &operators, &postfix, lastToken);
        else if (contains("+-*/%", *expr))
            lastToken = pushOperator(&expr, &operators, &postfix, lastToken);
        else if (*expr == ' ')
            ++expr;
        else 
            cleanup_n_die(INVALID_CHAR_ERR_MSG, &operators, &postfix);
    }
    // syntax error: bad ending expression
    if (lastToken != tt_term && lastToken != tt_parClose)
        cleanup_n_die(SYNTAX_ERR_MSG, &operators, &postfix);
    transferRemainingOperators(&operators, &postfix);
    return postfix;
}

int eval_postfix(t_token* postfix)
{
    t_token* terms = NULL;
    postfix = postfix->tail;
    while (postfix) {
        if (!postfix->op)
            transferBackToken(&postfix, &terms);
        else {
            int lhs = terms->next->nb;
            int rhs = terms->nb;
            pop(&terms);
            if (!rhs && contains("/%", postfix->op))
                cleanup_n_die(ZERO_DIV_ERR_MSG, &terms, &postfix);
            terms->nb = do_op(postfix->op, lhs, rhs);
            postfix = postfix->prev;
        }
    }
    return terms->nb;
}

//#define RECURSIVE_DESCENT_PARSING
#ifndef RECURSIVE_DESCENT_PARSING
/* Reverse polish notation */
int eval_expr(char* expr)
{
    t_token* postfix = toPostfix(expr);
    //printPostfix(postfix);

    int res = eval_postfix(postfix);
    deleteStack(&postfix);
    return res;
}
#else
/* Recursive descent parsing */
int eval_expr(char* expr)
{
    int res = parseSum(&expr);
    if (*expr) {
        if (*expr == ')')
            ft_putstr("error: eval_expr(): missing parenthesis\n");
        else if (*expr == '(' || *expr >= '0' && *expr <= '9')
            ft_putstr("error: eval_expr(): missing operator\n");
        else
            ft_putstr("error: eval_expr(): invalid character\n");
        exit(1);
    }
    return res;
}
#endif