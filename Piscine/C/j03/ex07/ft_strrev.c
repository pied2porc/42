char* ft_strrev(char* str)
{
    char* firstHalf = str;
    char* secondHalf = firstHalf;
    while (*(secondHalf + 1))
        ++secondHalf;
    while (firstHalf < secondHalf) {
        char tmp = *firstHalf;
        *firstHalf = *secondHalf;
        *secondHalf = tmp;
        ++firstHalf; --secondHalf;
    }
    return str;
}