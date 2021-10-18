void  ft_putstr(char const*);
char* ft_strrev(char*);

int main()
{
    char s1[] = "a";
    char s2[] = "ab";
    char s3[] = "abcde";
    
    ft_putstr(s1); ft_putstr(" => "); ft_strrev(s1);
    ft_putstr(s1); ft_putstr("\n");
    ft_putstr(s2); ft_putstr(" => "); ft_strrev(s2);
    ft_putstr(s2); ft_putstr("\n");
    ft_putstr(s3); ft_putstr(" => "); ft_putstr(ft_strrev(s3)); ft_putstr("\n");
    ft_putstr("xyz => "); ft_putstr(ft_strrev("xyz")); ft_putstr("\n");

    return 0;
}