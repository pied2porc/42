#pragma once

int         ft_atoi(char const*);
long long   ft_atoll(char const*);
int         ft_compact(char const **, int);
char*       ft_itoh(unsigned int, char*, int);
char*       ft_join(char const**, char const*);
int         ft_max(int*, int);
void        ft_putaddr(void const*);
void        ft_putbit(long long, int);
void        ft_putchar(char);
void        ft_putnbr(int);
void        ft_putstr(char const*);
char**      ft_split(char const*, char const*);
char*       ft_strcat(char*, char const*);
int         ft_strcmp(char const*, char const*);
char*       ft_strcpy(char*, char const*);
char*       ft_strdup(char const*);
void        ft_strip_spaces(char*);
int         ft_strlen(char const*);
char*       ft_strndup(char const*, int);
void        ft_swap(int*, int*);