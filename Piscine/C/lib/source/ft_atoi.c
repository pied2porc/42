int ft_atoi(char const* str)
{
    while (*str && (*str <= 32 || *str == 127))
        ++str;
    int neg = 0;
    while (*str == '-' || *str == '+' || *str == ' ') {
        if (*str == '-')
            neg = !neg;
        ++str;
    }
    int res = 0;
    while (*str >= '0' && *str <= '9') {
        res = res * 10 + *str - '0';
        ++str;
    }
    return neg ? -res : res;
}