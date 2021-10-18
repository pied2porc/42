void ft_putnbr(int);
int  ft_max(int*, int);

int main()
{
    int tab[] = { 9,1,5,3,56,0,99,42,12 };

    ft_putnbr(ft_max(tab, 8));
    return 0;
}