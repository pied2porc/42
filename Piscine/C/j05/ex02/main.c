void        ft_putstr(char const*);
char const* ft_strstr(char const*, char const*);

int main()
{
    char const* str = "Try not. Do, or do not. There is no try.";
    char const* target = "not";
    char const* result = str;

    while ((result = ft_strstr(result, target)) != 0) {
        ft_putstr("Found '"); ft_putstr(target);
        ft_putstr("' starting at '"); ft_putstr(result);
        ft_putstr("'\n");
        ++result;
    }
    return 0;
}