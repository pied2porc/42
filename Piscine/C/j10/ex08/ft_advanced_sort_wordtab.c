void ft_advanced_sort_wordtab(char** tab, int(*cmp)(char const*, char const*))
{
    if (!tab || tab && (!tab[0] || !tab[1])) return;

    int i = -1;
    while (tab[++i]) {
        int j = i + 1;
        while (--j && cmp(tab[j - 1], tab[j]) > 0) {
            char* toInsert = tab[j];
            tab[j] = tab[j - 1];
            tab[j - 1] = toInsert;
        }
    }
}