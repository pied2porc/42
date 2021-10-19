#pragma once
#include <stdio.h>

#define STD_IN  0
#define STD_OUT 1

#define MAX_READ_LINES  10

int   ft_strlen(char const*);

void  ft_print_header(char**, int);
void  ft_print_body(char const*, t_opt*);
char* ft_fill_buffer(FILE**, char*, int);
void  ft_tail(char*, int, char**, t_opt*, char const*);