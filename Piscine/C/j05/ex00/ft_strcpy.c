char* ft_strcpy(char* dst, char const* src)
{
    char* cur = dst;
    while (*src != '\0') {
        *cur = *src;
        ++src; ++cur;
    }
    *cur = '\0';

    return dst;
}