char const* ft_strstr(char const* str, char const* to_find)
{
    if (!*to_find) return 0;

    char const*  target = to_find;
    unsigned int match = 0;

    while (*str != '\0' && *target != '\0') {
        if (*str == *target) {
            ++target; ++match;
        }
        else {
            target = to_find;
            match = 0;
        }
        ++str;
    }
    return (*target == '\0' ? str - match : 0);
}