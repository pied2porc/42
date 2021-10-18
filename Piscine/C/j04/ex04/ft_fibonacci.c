#define _RECURSIVE
#ifdef _RECURSIVE
int ft_fibonacci(int index)
{
    if (index < 0)
        return -1;
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;
    return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
#else
int ft_fibonacci(int index)
{
    if (index < 0)
        return -1;
    int i0 = 0, i1 = 1, i2 = 0 ;
    if (index == 1)
        return i1;
    while (index >= 2) {
        i2 = i1 + i0;
        i0 = i1;
        i1 = i2;
        --index;
    }
    return i2;
}
#endif