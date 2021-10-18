char* ft_strlowcase(char* str)
{
    char*       cur = str;
    static char offset = 'a' - 'A';

    while (*cur != '\0') {
        if (*cur >= 'A' && *cur <= 'Z')
            *cur += offset;
        ++cur;
    }
    return str;
}