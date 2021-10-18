int ft_iterative_factorial(int nb)
{
    if (nb < 0 || nb > 12)
        return 0;
    int res = 1;
    while (nb > 1)
        res *= nb--;
        
    return res;
}