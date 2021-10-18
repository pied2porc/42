#include <io.h>

void ft_uncapitalize(char* s)
{
    while (*s) {
        if (*s >= 'A' && *s <= 'Z')
            *s += 'a' - 'A';
        ++s;
    }
}

void ft_strip_spaces(char* s)
{
    char* seek = s;
    while (*s) {
        while (*seek == ' ' || *seek == '\t')
            ++seek;
        if ((*s = *seek) == '\0')
            break;
        ++s; ++seek;
    }
}

int ft_strcmp(char const* s1, char const* s2)
{
    while (*s1 && *s2 && *s1 == *s2) {
        ++s1; ++s2;
    }
    return *s2 - *s1;
}

int ft_alert(char* str)
{
    char const* dico[] = { "president", "attentat", "bauer", 0 };

    ft_uncapitalize(str);
    ft_strip_spaces(str);
    int i = -1;
    while (dico[++i])
        if (!ft_strcmp(str, dico[i])) {
            _write(1, "Alert!!!\n", 9);
            return 1;
        }
    return 0;
}

int main(int ac, char* av[])
{
    int i = 0;
    while (++i < ac && !ft_alert(av[i]));
    
    return 0;
}