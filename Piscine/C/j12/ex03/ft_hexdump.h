#pragma once
#include <stdio.h>

#define STD_IN  0
#define STD_OUT 1

#define MAX_BYTE   16
#define COL1_WIDTH 10
#define COL2_WIDTH ((MAX_BYTE * 2) + (MAX_BYTE - 2) + 4)
#define COL3_WIDTH (MAX_BYTE + 2)

#define LINE_WIDTH (COL1_WIDTH + COL2_WIDTH + COL3_WIDTH + 1)
#define BUF_SIZE   (1 * LINE_WIDTH)

#define MIN(a, b) ((a < b) ? a : b)

typedef struct s_buffer {
    char  input[BUF_SIZE];
    char  output[BUF_SIZE];
    char* i_ptr;
    char* o_ptr;
    unsigned int input_offset;
} t_buffer;

char* ft_itoh(unsigned int, char*, int);

int   ft_isPrintable(char);
void  ft_fill_hexa_ascii(t_buffer*, int);
void  ft_fill_offset(t_buffer*);
void  ft_fill_buffer(t_buffer*, int);
void  ft_flush_buffer(t_buffer*);