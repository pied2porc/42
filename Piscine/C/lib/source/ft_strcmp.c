int ft_strcmp(char const* s1, char const* s2)
{
    if (!s1 || !s2) return 0;
    while (*s1 && *s2 && *s1 == *s2) {
        ++s1; ++s2;
    }
    return *s1 - *s2;
}