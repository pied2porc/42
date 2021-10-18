void ft_putchar(char);

void printMove(int src, int dst)
{
    ft_putchar((char)(src + '0'));
    ft_putchar('-');
    ft_putchar('>');
    ft_putchar((char)(dst + '0'));
    ft_putchar('\n');
}

void solve(int disks, int src, int dst)
{
    if (disks == 1)
        printMove(src, dst);
    else {
        int other = 6 - (src + dst);
        solve(disks - 1, src, other);
        printMove(src, dst);
        solve(disks - 1, other, dst);
    }
}

void hanoi(int disks) { solve(disks, 1, 3); }