int ft_str_is_lowercase(char const* str)
{
    while (*str != '\0') {
        if (*str < 'a' || *str > 'z')
            return 0;
        ++str;
    }
    return 1;
}