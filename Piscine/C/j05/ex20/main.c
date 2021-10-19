void const* ft_print_memory(void const*, unsigned int);

int main()
{
    ft_print_memory("Salut les aminches c'est cool show mem on fait de truc terrible"
        "\x00.\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0e\x0f\x1b\x7f", 79);
    return 0;
}