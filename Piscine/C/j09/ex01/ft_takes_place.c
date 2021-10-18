#include <stdio.h>

#define TIME_SUFFIX(hour)   (hour >= 12 && hour < 24 ? "P.M." : "A.M.")

int ft_convert(int h)
{
    if (h == 0 || h == 24 || h == 12)
        return 12;
    return h % 12;
}

void ft_takes_place(int hour)
{
    printf("THE FOLLOWING TAKES PLACE BETWEEN "
           "%d.00 %s AND %d.00 %s\n",
           ft_convert(hour), TIME_SUFFIX(hour),
           ft_convert(hour + 1), TIME_SUFFIX(hour + 1));
}