void ft_putchar(char);

void ft_print_comb() {
    int u = 0, d = 0, c = 0;
    int n = -1;
    while (++n < 800) {
        u = n % 10;
        d = n % 100 / 10;
        c = n / 100;

        if (u > d && d > c) {
            if (u > 2) {
                ft_putchar(',');
                ft_putchar(' ');
            }
            ft_putchar('0' + (char)c);
            ft_putchar('0' + (char)d);
            ft_putchar('0' + (char)u);
        }
    }
}
