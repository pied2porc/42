#pragma once

#define BUF_SIZE    (1024 * 30)

enum e_opt {
    c_opt,
    max_options
};

typedef struct s_opt {
    int     idx;
    char*   arg;
} t_opt;

int    ft_atoi(char const*);

char** ft_get_filenames(int, char**, t_opt*);
int    ft_get_num_bytes(char const*);
int    ft_check_num_bytes(char const*);
int    ft_get_buffer_size(t_opt*);
int    ft_get_optArg(int*, int, char**, t_opt*);
int    ft_parse_options(int, char**, t_opt*);