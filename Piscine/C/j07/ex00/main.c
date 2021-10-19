#include <stdlib.h>
void  ft_putaddr(void const*);
void  ft_putstr(char const*);
char* ft_strdup(const char*);

int main()
{
    char const* str = "Hello!";
    char*       dup = ft_strdup(str);
    ft_putaddr((void*)str); ft_putstr(" "); ft_putstr(str); ft_putstr("<\n");
    ft_putaddr((void*)dup); ft_putstr(" "); ft_putstr(dup); ft_putstr("<\n");

    free(dup);
    return 0;
}