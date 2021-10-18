#include "eval_expr.h"
#include "eval_utils.h"
#include "stack.h"
#include "tokenize.h"
#include "transfer_token.h"
#include <stdlib.h>

void transferToken(t_token** src, t_token** dst)
{
    t_token* toMove = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    toMove->next = *dst;
    if (*dst) {
        (*dst)->prev = toMove;
        toMove->tail = (*dst)->tail;
    }
    else
        toMove->tail = toMove;
    *dst = toMove;
}

void transferBackToken(t_token** src, t_token** dst)
{
    t_token* toMove = *src;
    *src = (*src)->prev;
    if (*src)
        (*src)->next = NULL;
    toMove->next = *dst;
    if (*dst) {
        (*dst)->prev = toMove;
        toMove->tail = (*dst)->tail;
    }
    else
        toMove->tail = toMove;
    *dst = toMove;
}

void transferOperators(char op, t_token** operators, t_token** postfix)
{
    while (*operators && getPrecedence(op) <= getPrecedence((*operators)->op))
        transferToken(operators, postfix);
    t_token t = { 0, op, tt_operator, NULL };
    push(&t, operators);
}

void transferRemainingOperators(t_token** operators, t_token** postfix)
{
    while (*operators) {
        if ((*operators)->op == '(')
            cleanup_n_die(PAREN_ERR_MSG, operators, postfix);
        transferToken(operators, postfix);
    }
}