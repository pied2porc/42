/**
 * @return the new length of the tab.
 */
int ft_compact(char const ** tab, int len)
{
    char const** end = tab + len;
    char const** seek = tab;
    int          nil_count = 0;
    while (seek < end) {
        while (seek < end && !*seek) {
            ++seek; ++nil_count;
        }
        *tab = *seek;
        ++tab; ++seek;
    }
    return len - nil_count;
}