#pragma once
#include "tokenize.h"

void cleanup_n_die(char const* msg, t_token** stack1, t_token** stack2);
int  contains     (char const* s, char c);
int  do_op        (char op, int lhs, int rhs);
int  getPrecedence(char op);
int  getSign      (char** expr);
