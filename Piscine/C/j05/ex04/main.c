void ft_putnbr(int);
void ft_putstr(char const*);
int  ft_strncmp(char const*, char const*, unsigned int);

void demo(char const* lhs, char const* rhs, int sz)
{
    int rc = ft_strncmp(lhs, rhs, sz);
    if (rc == 0) {
        ft_putstr("First "); ft_putnbr(sz); ft_putstr(" chars of [");
        ft_putstr(lhs); ft_putstr("] equal ["); ft_putstr(rhs); ft_putstr("]\n");
    }
    else if (rc < 0) {
        ft_putstr("First "); ft_putnbr(sz); ft_putstr(" chars of [");
        ft_putstr(lhs); ft_putstr("] precede ["); ft_putstr(rhs); ft_putstr("]\n");
    }
    else if (rc > 0) {
        ft_putstr("First "); ft_putnbr(sz); ft_putstr(" chars of [");
        ft_putstr(lhs); ft_putstr("] follow ["); ft_putstr(rhs); ft_putstr("]\n");
    }
}

int main()
{
    demo("Hello, world!", "Hello, everybody!", 13);
    demo("Hello, everybody!", "Hello, world!", 13);
    demo("Hello, everybody!", "Hello, world!", 7);
    demo("Hello, everybody!" + 12, "Hello, somebody!" + 11, 5);

    return 0;
}