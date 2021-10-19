int ft_any(char const** tab, int(*f)(char const*))
{
    int i = -1;
    while (tab[++i])
        if (f(tab[i]))
            return 1;
    return 0;
}