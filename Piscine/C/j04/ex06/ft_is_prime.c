int ft_is_prime(int nb)
{
    if (nb < 2)
        return 0;
    int i = 3;
    while (i * i <= nb) {
        if (!(nb % i))
            return 0;
        i += 2;             // Test only odd numbers
    }
    return 1;
}