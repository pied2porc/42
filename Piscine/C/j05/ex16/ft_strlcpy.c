/**
 * Copies up to size - 1 characters from the NUL-terminated string src
 * to dst, NUL-terminating the result.
 * @param size: size of the dst buffer.
 * @return the length of the created string.
 */
unsigned int ft_strlcpy(char* dst, char const* src, unsigned int size)
{
    char const*  cur = src;
    unsigned int len = 0;
    while (++len < size && *cur != '\0') {
        *dst = *cur;
        ++dst; ++cur;
    }
    *dst = '\0';

    return cur - src;
}