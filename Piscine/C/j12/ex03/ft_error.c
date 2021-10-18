#include "ft_error.h"
#include <errno.h>
#include <io.h>

void ft_print_error(char const* msg)
{
    int count = -1;
    while (msg[++count]);
    _write(STD_ERR, msg, count);
}

void ft_print_file_error(char const* cmd, char const* file)
{
    ft_print_error(ft_get_command_name(cmd));
    ft_print_error(": ");
    ft_print_error(file);
    if (errno == ENOENT)
        ft_print_error(": No such file or directory\n");
    else if (errno == EISDIR)
        ft_print_error(": Is a directory\n");
    else if (errno == EACCES)
        ft_print_error(": Permission denied\n");
}

void ft_print_arg_error(char const* cmd, char const* arg, char const* msg)
{
    ft_print_error(ft_get_command_name(cmd));
    ft_print_error(": ");
    ft_print_error(msg);
    ft_print_error(" '");
    ft_print_error(arg);
    ft_print_error("'\n");
}

char const* ft_get_command_name(char const* s)
{
    char const* begin = s;
    while (*s != '\0') ++s;
    while (s > begin && *s != '\\') --s;
    return ++s;
}