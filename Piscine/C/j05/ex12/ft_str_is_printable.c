int ft_str_is_printable(char const* str)
{
    while (*str != '\0') {
        if (*str >= 0 && *str <= ' ')
            return 0;
        ++str;
    }
    return 1;
}