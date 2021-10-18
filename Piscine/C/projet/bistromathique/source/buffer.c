#include "bistromathique.h"
#include <io.h>

void freeBuffer(char* buf, char const* msg)
{
    ft_putstr(msg, CERR);
    free(buf);
    buf = NULL;
}

/**
 * Fill the buffer with the expression to parse from the standard input.
 * @param size: requested size to read.
 * @return the length of the buffer.
 */
size_t fill_buffer(char** buf, unsigned int size)
{
    if (size < 1) {
        ft_putstr(READ_SIZE_ERR, CERR);
        return 0;
    }
    *buf = malloc(size + 1);
    if (!*buf) {
        ft_putstr(MALLOC_ERR, CERR);
        return 0;
    }
    unsigned int pos = 0;
    int size_read;
    // _read() returns 0 when there is no more bytes to read or if the
    // requested size has reached 0.
    while ((size_read = _read(CIN, *buf + pos, size + 1 - pos)) > 0) {
        if (size_read == -1) {
            freeBuffer(*buf, READ_ERR);
            return 0;
        }
        pos += size_read;
    }
    if (pos != size + 1 || (*buf)[size] != '\n' && (*buf)[size] != '\0')
        ft_putstr(READ_SIZE_MIS, CERR);
    (*buf)[pos - 1] = 0;
    return pos;
}