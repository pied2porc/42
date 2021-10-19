#define _CRT_SECURE_NO_WARNINGS
#include "ft_error.h"
#include "ft_option.h"
#include "ft_tail.h"
#include <stdlib.h>
#include <stdio.h>
#include <io.h>

void ft_print_header(char** files, int i)
{
    if (i > 0)
        _write(STD_OUT, "\n", 1);
    if (!files[1])
        return;
    _write(STD_OUT, "==> ", 4);
    _write(STD_OUT, files[i], ft_strlen(files[i]));
    _write(STD_OUT, " <==\n", 5);
}

/**
 * Print buffer, up to 10 lines if no option was specified.
*/
void ft_print_body(char const* buf, t_opt* optTab)
{
    char const* end = buf + ft_strlen(buf) - 1;
    char const* pos = *end == '\n' ? end - 1 : end;
    int line_count = 0;
    while (pos != buf && (optTab[c_opt].arg ||
          (!optTab[c_opt].arg && line_count < MAX_READ_LINES))) {
        if (*pos == '\n')
            ++line_count;
        --pos;
    }
    pos += (line_count == MAX_READ_LINES && *(pos + 1) == '\n') ? 2 : 0;
    _write(STD_OUT, pos, end - pos + 1);
}

char* ft_fill_buffer(FILE** fd, char* buf, int buf_size)
{
    int size_read = 0;
    int read_count = 0;
    // Count the number of chunks of size buf_size.
    // If the number of characters in the file is not a multiple of buf_size,
    // size_read will be equal to the number of remaining characters.
    while ((size_read = fread(buf, sizeof(*buf), buf_size, fd[0])) == buf_size)
        ++read_count;

    if (read_count) {
        // Read again and stop before the last chunk of characters.
        while (--read_count > 0)
            fread(buf, sizeof(*buf), buf_size, fd[1]);
        // Read the excess of characters.
        fread(buf, sizeof(*buf), size_read, fd[1]);
        // The last read should be exactly the size of buf_size.
        size_read = fread(buf, sizeof(*buf), buf_size, fd[1]);
    }
    buf[size_read] = 0;
    return buf;
}

void ft_tail(char* buf, int buf_size, char** files, t_opt* optTab, char const* cmd)
{
    int i = -1;
    while (files[++i]) {
        FILE* fd[] = { fopen(files[i], "r"), fopen(files[i], "r") };
        if (!fd[0] || !fd[1]) {
            ft_print_file_error(cmd, files[i]);
            continue;
        }
        buf = ft_fill_buffer(fd, buf, buf_size);
        ft_print_header(files, i);
        ft_print_body(buf, optTab);
        fclose(fd[0]);
        fclose(fd[1]);
    }
}