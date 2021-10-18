
int isValid(int pos[], int col, int row)
{
    int i = -1;
    while (++i < col)
    // Property of diagonals: row +/- col = unique constant
        if (pos[i] == row ||
            i + pos[i] == col + row ||  // Forward diagonals '/'
            i - pos[i] == col - row)    // Backward diagonals '\'
            return 0;
    return 1;
}

void solve(int* count, int pos[8], int col)
{
    if (col == 8)
        *count += 1;
    else {
        int row = -1;
        while (++row < 8)
            if (isValid(pos, col, row)) {
                pos[col] = row;
                solve(count, pos, col + 1);
            }
    }
}

int ft_eight_queens_puzzle(void)
{
    int pos[8] = { 0 };
    int count = 0;

    solve(&count, pos, 0);
    return count;
}