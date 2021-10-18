#include <io.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN_WIDTH  7

void ft_putchar(char c);

void printSpace(int len)
{
    while (len > 0) {
        ft_putchar(' ');
        --len;
    }
}

void printWall(int len)
{
    ft_putchar('/');
    while (--len > 1)
        ft_putchar('*');
    ft_putchar('\\');
    ft_putchar('\n');
}

void printWallAndDoor(int len, int height, int doorSize)
{
    struct s_door { int begin; int end; };
    struct s_door door = { (len - doorSize) / 2 + 1, door.begin + doorSize };
    struct s_knob { int x; int y; };
    struct s_knob knob = { door.end - 2, doorSize / 2 + 1 };
    ft_putchar('/');
    int pos = 1;
    while (++pos < len) {
        if (doorSize && pos >= door.begin && pos < door.end) {
            if (doorSize > 4 && height == knob.y && pos == knob.x)
                ft_putchar('$');
            else
                ft_putchar('|');
        }
        else ft_putchar('*');
    }
    ft_putchar('\\');
    ft_putchar('\n');
}

int getMaxWidth(int size)
{
    if (size == 1) return MIN_WIDTH;
    int height = size + 2;
    int enlarge = (size / 2) * 2 + 2;
    return getMaxWidth(size - 1) + 2 * height + enlarge;
}

void sastantua(int size) {
    if (size < 1)
        return;
    int maxWidth = getMaxWidth(size);
    int doorSize = size - (size + 1) % 2;
    int width = 1;
    int level = 1;
    while (level <= size) {
        width += (level / 2) * 2 + 2;
        int height = level + 2;
        while (height) {
            printSpace((maxWidth - width) / 2);
            if (level == size && !(height > doorSize))
                printWallAndDoor(width, height, doorSize);
            else
                printWall(width);
            width += 2;
            --height;
        }
        ++level;
    }
}