char* ft_strcat(char* dst, char const* src)
{
    char* ptr = dst - 1;
    while (*(++ptr));

    int dst_len = ptr - dst;
    int i = -1;
    while (src[++i])
        dst[dst_len + i] = src[i];
    dst[dst_len + i] = '\0';
    return dst;
}