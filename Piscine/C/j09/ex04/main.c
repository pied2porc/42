#include <stdlib.h>

void  ft_putstr(char const*);
char* ft_rot42(char*);

int main()
{
    ft_putstr(ft_rot42("abcdefghijklmnopqrstuvwxyz"));
    ft_putstr("\n");
    ft_putstr(ft_rot42("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    ft_putstr("\n");
    return 0;
}