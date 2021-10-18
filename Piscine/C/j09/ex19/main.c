void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_unmatch(int*, int);

int main()
{
    int tab1[] = { 1,1,2,3,4,3,4 };
    ft_putnbr(ft_unmatch(tab1, 7)); ft_putstr(" ");

    int tab2[] = { 1,1,2,4,3,4,2,3,4 };
    ft_putnbr(ft_unmatch(tab2, 9)); ft_putstr(" ");

    return 0;
}