#include "bistromathique.h"

/**
 * @return the numerical value of a character in a given base.
 * Since we're dealing with a string of char, the base could
 * have a maximum of 128 unique characters.
 */
int getNumberValue(char c, char const* base)
{
    int index = 0;
    while (base[index] && base[index] != c)
        ++index;
    return index;
}

/**
 * Convert a string in place from an ascii value to its
 * numerical value in a given base.
 * @return a pointer to the last converted character.
 */
char* digitToValue(char* str, char const* base, int base_len)
{
    int   value = 0;
    while (*str && (value = getNumberValue(*str, base)) < base_len) {
        *str = (char)value;
        ++str;
    }
    return str;
}

/**
 * Convert a string in place from a numerical value in a given base
 * to its ascii value.
 */
void valueToDigit(char* str, char* end, char const* base)
{
    while (str < end) {
        *str = base[*str];
        ++str;
    }
}

void setStringToZero(char* str, char* end)
{
    if (!str) return;
    while (str < end) {
        *str = 0;
        ++str;
    }
}