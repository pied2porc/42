void ft_putnbr(int);
void ft_scrambler(int***, int*, int******, int****);

int main()
{
    int   a1 = 1;
    int*  a2 = &a1;
    int** a3 = &a2;
    int*** a = &a3;

    int b1 = 2;
    int* b = &b1;

    int      c1 = 3;
    int*     c2 = &c1;
    int**    c3 = &c2;
    int***   c4 = &c3;
    int****  c5 = &c4;
    int***** c6 = &c5;
    int****** c = &c6;

    int    d1 = 4;
    int*   d2 = &d1;
    int**  d3 = &d2;
    int*** d4 = &d3;
    int**** d = &d4;

    ft_scrambler(a, b, c, d); // 2413
    ft_putnbr(***a);
    ft_putnbr(*b);
    ft_putnbr(******c);
    ft_putnbr(****d);
    
    return 0;
}