void ft_putnbr(int);
int  ft_is_sort(int*, int, int(*)(int, int));

int ft_intcmp(int a, int b) { return a - b; }

int main()
{
    int tab1[] = { 9,8,7,6,5,4,3,2,1,0 };
    int tab2[] = { 5,8,2 };
    ft_putnbr(ft_is_sort(tab1, 10, &ft_intcmp));
    ft_putnbr(ft_is_sort(tab2, 3, &ft_intcmp));
    return 0;
}