int ft_iterative_power(int nb, int power)
{
    if (power < 0)
        return 0;
    int res = 1;
    while (power--)
        res *= nb;
    return res;
}