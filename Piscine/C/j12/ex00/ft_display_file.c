#define _CRT_SECURE_NO_WARNINGS
#include "ft_display_file.h"
#include "ft_error.h"
#include <stdio.h>
#include <io.h>

void ft_display_file(char const* file)
{
    FILE* fs = fopen(file, "r");
    if (!fs) {
        ft_print_file_error(file);
        return;
    }
    char buf[BUFFER_SIZE];
    int n = 0;
    while ((n = fread(buf, sizeof(*buf), BUFFER_SIZE, fs)) > 0)
        _write(STD_OUT, buf, n);
    fclose(fs);
}
