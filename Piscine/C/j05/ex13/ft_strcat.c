char* ft_strcat(char* dst, char const* src)
{
    char* cur = dst;
    while (*cur != '\0')
        ++cur;
    while (*src != '\0') {
        *cur = *src;
        ++cur; ++src;
    }
    *cur = '\0';

    return dst;
}