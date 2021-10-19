void  ft_putstr(char const*);
char* ft_strcat(char*, char const*);

int main()
{
    char str[50] = "Hello ";
    char str2[50] = "World!";
    ft_strcat(str, str2);
    ft_strcat(str, " Goodbye World!");
    ft_putstr(str);
    
    return 0;
}