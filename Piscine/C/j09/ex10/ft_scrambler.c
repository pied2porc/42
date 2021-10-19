void ft_scrambler(int*** a, int* b, int****** c, int**** d)
{
    int tmp = ***a;
    ***a = *b;
    *b = ****d;
    ****d = ******c;
    ******c = tmp;
}