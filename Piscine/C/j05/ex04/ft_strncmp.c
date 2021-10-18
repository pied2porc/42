int ft_strncmp(char const* s1, char const* s2, unsigned int n)
{
    while (--n && *s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        ++s1; ++s2;
    }
    if (!n)
        return 0;
    return *s1 - *s2;
}