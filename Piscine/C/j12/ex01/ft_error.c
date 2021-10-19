#include "ft_error.h"
#include <errno.h>
#include <io.h>

void ft_print_error(char const* msg)
{
    int count = -1;
    while (msg[++count]);
    _write(STD_ERR, msg, count);
}

void ft_print_file_error(char const* file)
{
    ft_print_error(file);
    if (errno == ENOENT)
        ft_print_error(": No such file or directory\n");
    else if (errno == EISDIR)
        ft_print_error(": Is a directory\n");
    else if (errno == EACCES)
        ft_print_error(": Permission denied\n");
}