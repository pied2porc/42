#include <stdio.h>

int match(char* s1, char* s2)
{
    if (*s1 == *s2)
        return *s1 ? match(s1+1, s2+1) : 1;
    if (*s2 == '*')
        return *s1 ? (match(s1+1, s2) || match(s1, s2+1)) : match(s1, s2+1);
    return 0;
}
/*
int match(char* s, char* p)
{
    while (*p) {
        while (*s && *p && *s == *p) { ++s; ++p; }
        if (*p == '*') {
            while (*p && *p == '*') ++p;
            if (!*p) return 1;
            char* lastMatch = s;
            while (*s) {
                if (*s == *p) lastMatch = s;
                ++s;
            }
            s = lastMatch;
        }
        else if (*s - *p) return 0;
    }
    return (!*s && !*p ? 1 : 0);
}
*/