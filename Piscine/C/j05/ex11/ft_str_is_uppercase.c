int ft_str_is_uppercase(char const* str)
{
    while (*str != '\0') {
        if (*str < 'A' || *str > 'Z')
            return 0;
        ++str;
    }
    return 1;
}