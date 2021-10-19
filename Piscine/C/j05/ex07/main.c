void  ft_putstr(char const*);
char* ft_strcapitalize(char*);

int main()
{
    char str[] = "salut, coMMent tu Vas ? 42mots quarante-deux; cinquante+et+un";
    ft_putstr(ft_strcapitalize(str));
    return 0;
}