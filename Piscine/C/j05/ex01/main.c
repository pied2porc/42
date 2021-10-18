void  ft_putchar(char);
char* ft_strncpy(char*, const char*, unsigned int);

int main()
{
    char const* src = "hi";
    char dst[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    ft_strncpy(dst, src, 5);

    int i = -1;
    while (++i < 6) {
        dst[i] ? ft_putchar(dst[i]): ft_putchar('0');
        if (i < 5)
            ft_putchar(',');
    }
    
    return 0;
}