char* ft_strupcase(char* str)
{
    char*        cur = str;
    static char  offset = 'A' - 'a';

    while (*cur != '\0') {
        if (*cur >= 'a' && *cur <= 'z')
            *cur += offset;
        ++cur;
    }
    return str;
}