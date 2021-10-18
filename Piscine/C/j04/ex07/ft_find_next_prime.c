int ft_is_prime(int);

int ft_find_next_prime(int nb)
{
    if (nb < 2)
        nb = 2;
    else            // Start with the next odd number
        nb += !(nb % 2) ? 1 : 2;
    while (!ft_is_prime(nb))
        nb += 2;    // Test only odd numbers

    return nb;
}