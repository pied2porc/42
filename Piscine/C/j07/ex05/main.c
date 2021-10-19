char** ft_split_whitespaces(char const*);
void   ft_print_words_tables(char**);

int main()
{
    char const* str = " \nHello World!\nGoodbye  World!\t\t42 \n";
    char**      array = ft_split_whitespaces(str);
    ft_print_words_tables(array);

    return 0;
}