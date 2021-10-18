char const* hexa = "0123456789abcdef";

void ft_putchar(char);

void ft_print_addr2hexa(void const* addr)
{
    unsigned int uiptr = (unsigned int)addr;

    int nibbles = sizeof(uiptr) * 2;
    while (--nibbles >= 0)
        ft_putchar(hexa[uiptr >> (4 * nibbles) & 0xf]);
}

void ft_print_line2hexa(char const* c, unsigned int size)
{
    unsigned int countChar = 0;
    while (++countChar <= size) {
        ft_putchar(hexa[*c >> 4]);
        ft_putchar(hexa[*c & 0xf]);
        if (!(countChar % 2))
            ft_putchar(' ');
        ++c;
    }
    if (countChar % 2)
        ft_putchar('\b');
}

void ft_print_line2char(char const* c, unsigned int size)
{
    ++size;
    while (--size) {
        ft_putchar((*c >= 32 && *c < 127) ? *c : '.');
        ++c;
    }
}

void const* ft_print_memory(void const* addr, unsigned int size)
{
    char const*  ptr = (char*)addr;
    unsigned int maxLineSize = 16;
    unsigned int lineSize = maxLineSize;

    while (size) {
        lineSize = size >= maxLineSize ? maxLineSize : size % lineSize;
        ft_print_addr2hexa(ptr);
        ft_putchar(':');
        ft_putchar(' ');
        ft_print_line2hexa(ptr, lineSize);
        unsigned int padding = 2 * (maxLineSize - lineSize) + 1;
        while (--padding)
            ft_putchar(' ');
        ft_putchar(' ');
        ft_putchar(' ');
        ft_print_line2char(ptr, lineSize);
        ft_putchar('\n');
        ptr += lineSize;
        size -= lineSize;
    }
    return addr;
}