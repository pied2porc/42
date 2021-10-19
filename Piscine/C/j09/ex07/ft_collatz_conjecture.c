unsigned int ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return 0;
	if (base % 2)
		return 1 + ft_collatz_conjecture(base * 3 + 1);
	return 1 + ft_collatz_conjecture(base / 2);
}