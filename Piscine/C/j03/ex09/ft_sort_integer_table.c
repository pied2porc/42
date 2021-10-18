void ft_sort_integer_table(int* tab, int size)
{
    int i = 0;
    while (i <= size) {
        int swapped = 0;
        int j = 0;
        while (j < size - 1) {
            if (tab[j] > tab[j + 1]) {
                int tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
                swapped = 1;
            }
            ++j;
        }
        if (!swapped)
            break;
        ++i; --size;
    }
}