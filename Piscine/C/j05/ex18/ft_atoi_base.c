int findChar(char const* str, char c)
{
    char const* cur = str;
    while (*cur) {
        if (*cur == c)
            return cur - str;
        ++cur;
    }
    return -1;
}

int containsDup(char const* str)
{
    while (*str) {
        if (findChar(str + 1, *str) >= 0)
            return 1;
        ++str;
    }
    return 0;
}

int baseLen(char const* base)
{
    char const* cur = base;
    while (*cur)
        ++cur;
    return cur - base;
}

int isValidBase(char const* base, int len)
{
    if (len <= 1 || findChar(base, '+') >= 0 || findChar(base, '-') >= 0 ||
        containsDup(base))
        return 0;
    return 1;
}

int isValidStr(char const* str, char const* base)
{
    if (*str == '\0')
        return 0;
    while (*str) {
        if (findChar(base, *str) < 0)
            return 0;
        ++str;
    }
    return 1;
}

int ft_atoi_base(char const* str, char const* base)
{
    if (*str == '+')
        return ft_atoi_base(str + 1, base);
    if (*str == '-')
        return -ft_atoi_base(str + 1, base);

    int len = baseLen(base);
    if (!isValidBase(base, len) || !isValidStr(str, base))
        return 0;

    int res = 0;
    while (*str) {
        res = res * len + findChar(base, *str);
        ++str;
    }
    return res;
}