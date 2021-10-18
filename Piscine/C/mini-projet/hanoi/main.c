int  ft_atoi(char const*);
void hanoi(int);

int main(int ac, char* av[])
{
    if (ac != 2) return;
    hanoi(ft_atoi(av[1]));
    return 0;
}