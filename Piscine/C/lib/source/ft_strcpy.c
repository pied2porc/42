char* ft_strcpy(char* dst, char const* src)
{
    char* cpy = dst;
    while (*src) {
        *dst = *src;
        ++dst; ++src;
    }
    *dst = *src;
    return cpy;
}