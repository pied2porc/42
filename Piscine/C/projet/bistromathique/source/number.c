#include "bistromathique.h"

/**
 * Compare absolute value
 */
int isSmallerThan(t_number* lhs, t_number* rhs)
{
    size_t lsize = lhs->end - lhs->value;
    size_t rsize = rhs->end - rhs->value;
    if (lsize < rsize || lsize == rsize &&
        ft_strncmp(lhs->value, rhs->value, lsize) < 0)
        return TRUE;
    return FALSE;
}

/**
 * Initialize a number to an existing value or allocate memory
 * for a new value.
 */
int initNumber(t_number* nb, char* value, size_t size, int sign)
{
    nb->value = value;
    nb->sign = sign;
    nb->pointsToBuffer = TRUE;
    if (!value && size) {
        if ((nb->value = malloc(size)) == NULL) {
            ft_putstr(MALLOC_ERR, CERR);
            return EXIT_FAILURE;
        }
        nb->pointsToBuffer = FALSE;
    }
    nb->begin = nb->value;
    nb->end = nb->begin + size;
    return EXIT_SUCCESS;
}

void freeNumber(t_number* nb)
{
    if (!nb) return;
    if (nb->begin && nb->pointsToBuffer == FALSE)
        free(nb->begin);
}

void swapNumber(t_number** lhs, t_number **rhs)
{
    t_number* tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}