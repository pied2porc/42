int   is_alphanum(char c)
{
    if ((c < 'a' || c > 'z') &&
        (c < 'A' || c > 'Z') &&
        (c < '0' || c > '9'))
        return 0;
    return 1;
}

char* ft_strcapitalize(char* str)
{
    char*       cur = str;
    static char offset = 'A' - 'a';

    while (*cur != '\0') {
        if (*cur >= 'a' && *cur <= 'z' &&
            (cur == str || !is_alphanum(*(cur - 1))))
            *cur += offset;
        else if (*cur >= 'A' && *cur <= 'Z' &&
                 (cur != str && is_alphanum(*(cur - 1))))
            *cur -= offset;
        ++cur;
    }
    return str;
}