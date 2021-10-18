void ft_ultimate_div_mod(int* a, int* b)
{
    int x = *a;
    int y = *b;

    *a = x / y;
    *b = x % y;
}