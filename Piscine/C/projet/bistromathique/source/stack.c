#include "bistromathique.h"

t_node* newNode(int op, e_tokenType tokenType)
{
    t_node* node = malloc(sizeof(*node));
    if (!node){
        ft_putstr(MALLOC_ERR, CERR);
        return NULL;
    }
    node->token.nb.begin = NULL;
    node->token.op = op;
    node->token.type = tokenType;
    node->tail = node;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

int push(t_node* node, t_node** stack)
{
    if (!node) return EXIT_FAILURE;
    node->next = *stack;
    if (*stack) {
        (*stack)->prev = node;
        node->tail = (*stack)->tail;
    }
    *stack = node;
    return EXIT_SUCCESS;
}

void pop(t_node** stack)
{
    t_node* toPop = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    freeNumber(&(toPop->token.nb));
    free(toPop);
}

void deleteStack(t_node** stack)
{
    while(*stack)
        pop(stack);
}

void removeNode(t_node** stack)
{
    if (!*stack) return;
    t_node* node = *stack;
    if (node->next) {
        *stack = (*stack)->next;
        (*stack)->prev = node->prev;
        if (node->prev)
            node->prev->next = *stack;
    }
    else if (node->prev) {
        *stack = (*stack)->prev;
        (*stack)->next = node->next;
        (*stack)->tail = *stack;
    }
    else
        *stack = NULL;
    freeNumber(&node->token.nb);
    free(node);
}

void transferNode(t_node** src, t_node** dst)
{
    t_node* toMove = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    push(toMove, dst);
}