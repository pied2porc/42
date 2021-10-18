int ft_count_if(char const** tab, int(*f)(char const*))
{
    int count = 0;
    int i = -1;
    while (tab[++i])
        if (f(tab[i]))
            ++count;
    return count;
}