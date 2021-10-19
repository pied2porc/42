void  ft_putstr(char const*);
char* ft_strcpy(char*, char const*);

int main()
{
    char const* src = "Take the test.";
    char cpy[15] = { 0 };
    ft_strcpy(cpy, src);
    cpy[0] = 'M';
    ft_putstr(src); ft_putstr("\n");
    ft_putstr(cpy); ft_putstr("\n");

    return 0;
}