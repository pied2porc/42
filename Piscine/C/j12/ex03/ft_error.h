#pragma once

#define STD_ERR 2

void        ft_print_error(char const*);
void        ft_print_file_error(char const*, char const*);
void        ft_print_arg_error(char const*, char const*, char const*);
char const* ft_get_command_name(char const*);