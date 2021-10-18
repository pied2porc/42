char* ft_rot42(char* str)
{
    char* cur = str - 1;
    while (*(++cur)) {
        if (*cur >= 'a' && *cur <= 'z')
            *cur = (*cur - 'a' + 42) % 26 + 'a';
        else if (*cur >= 'A' && *cur <= 'Z')
            *cur = (*cur - 'A' + 42) % 26 + 'A';
    }
    return str;
}