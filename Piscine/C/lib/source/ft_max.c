int ft_max(int* tab, int len)
{
    int max = tab[0];
    int i = -1;
    while (++i < len)
        if (tab[i] > max)
            max = tab[i];
    return max;
}