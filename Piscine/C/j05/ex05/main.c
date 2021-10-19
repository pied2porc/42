void  ft_putstr(char const*);
char* ft_strupcase(char*);

int main()
{
    char str[] = "abcdEfghIjklMnoqrstUVWxyz";
    ft_putstr(ft_strupcase(str));

    return 0;
}