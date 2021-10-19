char* ft_strncpy(char* dst, char const* src, unsigned int n)
{
    unsigned int pos = 0;
    while (src[pos] && pos < n) {
        dst[pos] = src[pos];
        ++pos;
    }
    while (pos < n) {
        dst[pos] = 0;
        ++pos;
    }
    return dst;
}