#include <stdio.h>
/*
int nmatch(char* s1, char* s2)
{
    if (*s1 == *s2)
        return *s1 ? nmatch(s1+1, s2+1) : 1;
    if (*s2 == '*')
        return *s1 ? (nmatch(s1+1, s2) + nmatch(s1, s2+1)) : nmatch(s1, s2+1);
    return 0;
}
*/
/*
int nmatch(char* s1, char* s2)
{
    while (*s1 && *s2 && *s1 == *s2) {
        ++s1; ++s2;
    }
    if (!(*s1 + *s2)) return 1;
    return (*s2-'*' ? 0 : (nmatch(s1, s2+1) + (*s1 ? nmatch(s1+1, s2) : 0)));
}
*/
int nmatch(char*, char*);
int (*f)(char*, char*) = nmatch;

int nmatch(char* s, char* p)
{
    return (*p - 42 ? *s - *p ? 0 : *s ? f(s + 1, p + 1) : 1 : f(s, p + 1) + (*s ? f(s + 1, p) : 0));
}