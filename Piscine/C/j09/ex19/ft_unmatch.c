int ft_unmatch(int* tab, int length)
{
    int i = -1;
    while (++i < length) {
        int found = 0;
        int j = -1;
        while (++j < length)
            if (i != j && tab[i] == tab[j])
                ++found;
        if (found == 0 || found > 1)
            return tab[i];
    }
    return 0;
}