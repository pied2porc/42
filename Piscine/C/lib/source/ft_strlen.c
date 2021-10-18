int ft_strlen(char const* str)
{
    if (!str) return -1;
    char const* ptr = str;
    while (*ptr)
        ++ptr;
    return ptr - str;
}