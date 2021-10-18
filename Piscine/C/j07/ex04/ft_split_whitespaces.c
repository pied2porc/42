#include <stdlib.h>

char* ft_strndup(char const*, int);

static char const* ft_get_beginWord(char const* str)
{
    while (*str && (*str <= 32 || *str >= 127))
        ++str;
    return str;
}

static char const* ft_get_endWord(char const* str)
{
    while (*str && *str > 32 && *str < 127)
        ++str;
    return str;
}

static int ft_count_words(char const* str)
{
    int count = 0;
    char const* end = 0;
    while (*str) {
        str = ft_get_beginWord(str);
        end = ft_get_endWord(str);
        if (end != str) {
            ++count;
            str = end;
        }
    }
    return count;
}

char** ft_split_whitespaces(char const* str)
{
    int    words = ft_count_words(str);
    char** tab = malloc(sizeof(char*) * (words + 1));
    if (!(tab)) return 0;
    
    int w = -1;
    char const* end = str;
    while (++w < words) {
        str = ft_get_beginWord(str);
        end = ft_get_endWord(str);
        tab[w] = ft_strndup(str, end - str);
        str = end;
    }
    tab[w] = 0;
    return tab;
}