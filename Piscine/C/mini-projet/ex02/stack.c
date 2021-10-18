#include "eval_expr.h"
#include "ft.h"
#include "stack.h"
#include <stdlib.h>

t_token* newToken(t_token* data)
{
    t_token* t = (t_token*)malloc(sizeof(*t));
    if (!t) {
        ft_putstr(MALLOC_ERR_MSG);
        exit(EXIT_FAILURE);
    }
    t->nb = data->nb;
    t->op = data->op;
    t->tt = data->tt;
    t->tail = t;
    t->next = NULL;
    t->prev = NULL;
    return t;
}

void push(t_token* data, t_token** stack)
{
    t_token* t = newToken(data);
    t->next = *stack;
    if (*stack) {
        (*stack)->prev = t;
        t->tail = (*stack)->tail;
    }
    *stack = t;
}

void pop(t_token** stack)
{
    if (!*stack) return;
    t_token* toPop = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(toPop);
}

void deleteStack(t_token** stack)
{
    while (*stack)
        pop(stack);
}