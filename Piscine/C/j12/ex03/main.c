#define _CRT_SECURE_NO_WARNINGS
#include "ft_error.h"
#include "ft_hexdump.h"
#include <stdlib.h>
#include <stdio.h>
#include <io.h>

int main(int ac, char* av[])
{
    if (ac < 2) return EXIT_FAILURE;
    t_buffer buf = { 0 };
    buf.o_ptr = buf.output;
    int i = ac;
    int size_read = 0;
    while (--i) {
        FILE* fd = fopen(av[ac - i] ,"r");
        if (!fd) {
            ft_print_file_error(av[0], av[ac - i]);
            continue;
        }
        while ((size_read =
               fread(buf.input, sizeof(char), BUF_SIZE, fd)) > 0) {
            buf.i_ptr = buf.input;
            ft_fill_buffer(&buf, size_read);
        }
        fclose(fd);
    }
    ft_flush_buffer(&buf);
    char offset[9] = { 0 };
    ft_itoh(buf.input_offset, offset, 8);
    _write(STD_OUT, offset, 8);
    return EXIT_SUCCESS;
}