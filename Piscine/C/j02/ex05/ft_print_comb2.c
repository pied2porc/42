void ft_putchar(char);

void ft_print_comb2() {
    int n1 = 0, n2 = 0;
    int n = 0;
    while (++n <= 10000) {
        n1 = n / 100;
        n2 = n % 100;
        if (n1 < n2) {
            if (n != 1) {
                ft_putchar(',');
                ft_putchar(' ');
            }
            ft_putchar('0' + (char)(n1 / 10));
            ft_putchar('0' + (char)(n1 % 10));
            ft_putchar(' ');
            ft_putchar('0' + (char)(n2 / 10));
            ft_putchar('0' + (char)(n2 % 10));
        }
    }
}