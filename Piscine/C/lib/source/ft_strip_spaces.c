/**
 * @return the new length of the string. 
 */
int ft_strip_spaces(char* s)
{
    char* begin = s;
    char* seek = s;
    while (*s) {
        while (*seek == ' ' || *seek == '\t')
            ++seek;
        if ((*s = *seek) == '\0')
            break;
        ++s; ++seek;
    }
    return s - begin;
}