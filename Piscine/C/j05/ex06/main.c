void  ft_putstr(char const*);
char* ft_strlowcase(char*);

int main()
{
    char str[] = "abcdEfghIjklMnoqrstUVWxyz";
    ft_putstr(ft_strlowcase(str));

    return 0;
}