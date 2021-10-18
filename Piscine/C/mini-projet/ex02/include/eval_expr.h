#pragma once
#include "tokenize.h"

#define INVALID_CHAR_ERR_MSG "invalid character\n"
#define MALLOC_ERR_MSG       "out of memory\n"
#define PAREN_ERR_MSG        "missing parenthesis\n"
#define SYNTAX_ERR_MSG       "syntax error\n"
#define ZERO_DIV_ERR_MSG     "divide by zero\n"

int      eval_expr(char* expr);
int      eval_postfix(t_token* postfix);
void     printPostfix(t_token* postfix);
t_token* toPostfix(char* expr);