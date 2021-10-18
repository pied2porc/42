
#include <stdio.h>

int match (char*, char*);
int nmatch(char*, char*);

int main()
{
    printf("%d ", match("hello", "hello"    ));
    printf("%d ", match("hollo", "h*o"      ));
    printf("%d ", match("hello", "hel*l*o"  ));
    printf("%d ", match("hello", "he**o**"  ));
    printf("%d ", match("hello", "*h*l"     )); // 0
    printf("%d ", match("hello", "he*w"     )); // 0
    printf("%d ", match("hello", "o***"     )); // 0
    printf("%d ", match("hello", "***"      ));

    printf("\n");
    printf("%d ", nmatch("hello", "hello"   )); // 1
    printf("%d ", nmatch("hollo", "h*o"     )); // 1
    printf("%d ", nmatch("hello", "hel*l*o" )); // 1
    printf("%d ", nmatch("hello", "he**o*"  )); // 3
    printf("%d ", nmatch("hello", "*h*l"    )); // 0
    printf("%d ", nmatch("hello", "he*w"    )); // 0
    printf("%d ", nmatch("hello", "o***"    )); // 0
    printf("%d ", nmatch("hello", "***"     )); // 21

    return 0;
}