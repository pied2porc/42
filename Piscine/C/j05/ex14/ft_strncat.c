char* ft_strncat(char* dest, char const* src, int nb)
{
    char* cur = dest;

    while (*cur != '\0')
        ++cur;
    while (--nb >= 0 && *src != '\0') {
        *cur = *src;
        ++cur; ++src;
    }
    *cur = '\0';

    return dest;
}