void ft_putchar(char);

void print(int pos[8])
{
    int i = -1;
    while (++i < 8)
        ft_putchar((char)(pos[i] + 1 + '0'));
    ft_putchar('\n');
}

int isValid(int pos[8], int col, int row)
{
    int c = -1;
    while (++c < col)
        if (pos[c] == row ||
            c + pos[c] == col + row ||
            c - pos[c] == col - row)
            return 0;
    return 1;
}

void solve(int pos[8], int col)
{
    int size = 8;
    if (col == size) {
        print(pos);
    }
    int row = -1;
    while (++row < size)
        if (isValid(pos, col, row)) {
            pos[col] = row;
            solve(pos, col + 1);
        }
}

void ft_eight_queens_puzzle_2(void)
{
    int pos[8] = { 0 };
    solve(pos, 0);
}