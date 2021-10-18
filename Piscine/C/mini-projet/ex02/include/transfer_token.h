#pragma once
#include "tokenize.h"

void transferToken(t_token** src, t_token** dst);
void transferBackToken(t_token** src, t_token** dst);
void transferOperators(char op, t_token** operators, t_token** postfix);
void transferRemainingOperators(t_token** operators, t_token** postfix);