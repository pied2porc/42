#include <stdlib.h>

char* ft_concat_params(int argc, char* argv[])
{
    if (argc == 1)
        return 0;

    int size = 0;
    int arg_pos = argc;
    int char_pos = -1;
    while (--arg_pos > 0) {
        char_pos = -1;
        while (argv[arg_pos][++char_pos])
            ++size;
    }
    char* params = malloc(size + argc - 1);
    if (!params)
        return 0;

    int c = -1;
    while (++arg_pos < argc) {
        char_pos = -1;
        while (argv[arg_pos][++char_pos])
            params[++c] = argv[arg_pos][char_pos];
        params[++c] = '\n';
    }
    params[c] = 0;

    return params;
}