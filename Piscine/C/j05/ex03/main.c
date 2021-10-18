void ft_putstr(char const*);
int  ft_strcmp(char const*, char const*);

void demo(char const* lhs, char const* rhs)
{
    int rc = ft_strcmp(lhs, rhs);
    char const* rel = rc < 0 ? "precedes" : rc > 0 ? "follows" : "equals";
    ft_putstr("["); ft_putstr(lhs); ft_putstr("] "); ft_putstr(rel);
    ft_putstr(" ["); ft_putstr(rhs); ft_putstr("]\n");
}
 
int main(void)
{
    char const* string = "Hello World!";
    demo(string, "Hello!");
    demo(string, "Hello");
    demo(string, "Hello there");
    demo("Hello, everybody!" + 12, "Hello, somebody!" + 11);

    return 0;
}