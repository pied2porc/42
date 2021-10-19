void  ft_putstr(char const*);
char* ft_join(char const**, char const*);

int main()
{
    char const* tab[] = { "Nick", "Chloe", "Jack", "John", "Kwame", 0 };
    ft_putstr(ft_join(tab, "***"));
    return 0;
}