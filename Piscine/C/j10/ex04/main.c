void ft_putnbr(int);
int  ft_count_if(char const**, int(*)(char const*));

int ft_is_num(char const* s)
{
    int i = -1;
    while (s[++i])
        if (s[i] < '0' || s[i] > '9')
            return 0;
    return 1;
}

int main()
{
    char const* tab[] = { "abc", "123", "42", "klm", "xyz", "456", 0 };
    ft_putnbr(ft_count_if(tab, &ft_is_num));
    return 0;
}