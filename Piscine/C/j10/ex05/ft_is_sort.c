int ft_is_sort(int* tab, int length, int(*f)(int, int))
{
    if (length <= 1)
        return 0;
        
    int i = -1;
    int asc = f(tab[0], tab[1]) < 0 ? 1 : 0;
    while (++i < length - 1) {
        int cmp = f(tab[i], tab[i + 1]);
        if (asc && cmp >= 0 || !asc && cmp <= 0)
            return 0;
    }
    return 1;
}