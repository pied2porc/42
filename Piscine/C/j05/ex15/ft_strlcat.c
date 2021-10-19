/**
 * Appends the NUL-terminated string src to the end of dst.
 * It will append at most size - strlen(dst) - 1 bytes, NUL-terminating
 * the result.
 * @param size: size of the dst buffer.
 * @return the sum of the length of both strings unless size is less
 * than the length of the dst string.
 */
unsigned int ft_strlcat(char* dst, char const* src, unsigned int size)
{
    char*        cur = dst - 1;
    unsigned int dst_len = 0;

    while (*(++cur) != '\0' && dst_len < size)
        ++dst_len;
    while (*src != '\0' && dst_len + 1 < size) {
        *cur++ = *src++;
        ++dst_len;
    }
    if (dst_len < size)
        *cur = '\0';
    while (*src != '\0') {
        ++src; ++dst_len;
    }
    return dst_len;
}