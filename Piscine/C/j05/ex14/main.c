void  ft_putstr(char const*);
char* ft_strncat(char*, char const*, int);

int main()
{
    char str[50] = "Hello World!";
    ft_strncat(str, " Goodbye World!", 3);
    ft_putstr(str);
    
    return 0;
}