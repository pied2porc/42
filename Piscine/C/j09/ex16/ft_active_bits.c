unsigned int ft_active_bits(int value)
{
    unsigned int count = 0;
    int          i = -1;
    while (++i < sizeof(value) * 8)
        if (value >> i & 1)
            ++count;
    return count;
}