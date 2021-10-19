void ft_swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int ft_antidote(int i, int j, int k)
{
    if (i > j)
        ft_swap(&i, &j);
    if (j > k)
        ft_swap(&j, &k);
    if (i > j)
        ft_swap(&i, &j);
    return j;
}