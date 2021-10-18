#include <stdlib.h>

static char const* ft_get_beginWord(char const* str, char const* charset)
{
    while (*str) {
        int found = 0;
        char const* cur = charset;
        while (*cur) {
            if (*str == *cur) {
                found = 1;
                break;
            }
            ++cur;
        }
        if (!found)
            return str;
        ++str;
    }
    return str;
}

static char const* ft_get_endWord(char const* str, char const* charset)
{
    while (*str) {
        char const* cur = charset;
        while (*cur) {
            if (*str == *cur)
                return str;
            ++cur;
        }
        ++str;
    }
    return str;
}

static int ft_count_words(char const* str, char const* charset)
{
    int count = 0;
    char const* end = 0;
    while (*str) {
        str = ft_get_beginWord(str, charset);
        end = ft_get_endWord(str, charset);
        if (end != str) {
            ++count;
            str = end;
        }
    }
    return count;
}

static void ft_cleanup(char** tab, char** end)
{
    char** ptr = tab;
    while (ptr < end) {
        free(*ptr);
        ++ptr;
    }
    free(tab);
}

char** ft_split(char const* str, char const* charset)
{
    int    words = ft_count_words(str, charset);
    char** tab = malloc(sizeof(char*) * (words + 1));
    if (!tab) return NULL;

    tab[words] = 0;
    words = -1;
    char const* end = str;
    while (tab[++words]) {
        str = ft_get_beginWord(str, charset);
        end = ft_get_endWord(str, charset);
        tab[words] = malloc((end - str) + 1);
        if (!tab[words]) {
            ft_cleanup(tab, tab + words);
            return NULL;
        }
        int c = -1;
        while (str != end) {
            tab[words][++c] = *str;
            ++str;
        }
        tab[words][++c] = 0;
    }
    return tab;
}