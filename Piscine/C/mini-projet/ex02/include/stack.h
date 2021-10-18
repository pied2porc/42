#pragma once
#include "eval_expr.h"
#include "tokenize.h"

t_token* newToken(t_token* data);
void     push(t_token* data, t_token** stack);
void     pop(t_token** stack);
void     deleteStack(t_token** stack);