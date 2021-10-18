#include "ft_hexdump.h"
#include <io.h>

int ft_isPrintable(char c)
{
    return (c > 31 ? 1 : 0);
}

void ft_flush_buffer(t_buffer* buf)
{
    int lastLine_len = (buf->o_ptr - buf->output) % LINE_WIDTH;
    if (lastLine_len) {
        int lastBytes = buf->input_offset % MAX_BYTE;
        char* end = buf->o_ptr + COL2_WIDTH;
        buf->o_ptr += lastBytes * 3 + (lastBytes > MAX_BYTE / 2);
        while (buf->o_ptr < end) {
            *buf->o_ptr = ' ';
            ++buf->o_ptr;
        }
        buf->o_ptr += 1 + lastBytes + 2;
        buf->o_ptr[-2] = '|';
        buf->o_ptr[-1] = '\n';
    }
    _write(STD_OUT, buf->output, buf->o_ptr - buf->output);
    buf->o_ptr = buf->output;
}

/**
 * Canonical hexa + ascii display format:
 * 00000000  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |0123456789abcdef|\n
 * Non-printing characters are displayed as a single '.'.
 */
void ft_fill_hexa_ascii(t_buffer* buf, int fillerBytes)
{
    int bytesRead = buf->input_offset % MAX_BYTE;
    int max_byte = bytesRead + fillerBytes;
    int pos = 0;
    while (bytesRead < max_byte) {
        pos = bytesRead * 3 + (bytesRead + 1 > MAX_BYTE / 2);
        // hexa
        ft_itoh(*buf->i_ptr, buf->o_ptr + pos, 2);
        buf->o_ptr[pos + 2] = ' ';
        // middle & end space
        if (bytesRead + 1 == MAX_BYTE / 2 || bytesRead + 1 == MAX_BYTE)
            buf->o_ptr[pos + 3] = ' ';
        // ascii
        buf->o_ptr[COL2_WIDTH + bytesRead + 1] =
            ft_isPrintable(*(buf->i_ptr)) ? *(buf->i_ptr) : '.'; 
        ++buf->i_ptr; ++bytesRead;
    }
    buf->input_offset += fillerBytes;
}

/**
 *  Input offset in hexadecimal.
 */
void ft_fill_offset(t_buffer* buf)
{
    ft_itoh(buf->input_offset, buf->o_ptr, 8);
    buf->o_ptr[8] = ' ';
    buf->o_ptr[9] = ' ';
    buf->o_ptr += COL1_WIDTH;
}

/**
 * Fill the buffer line by line.
 * The buffer size is a multiple of LINE_WIDTH to guarantee
 * enough space to format the display of MAX_BYTE bytes per line.
 */
void ft_fill_buffer(t_buffer* buf, int size_read)
{
    while (buf->i_ptr < buf->input + size_read) {
        int bytesLeft = size_read - (buf->i_ptr - buf->input);
        int spaceLeft = MAX_BYTE - buf->input_offset % MAX_BYTE;
        // Prevent unwanted execution when adding datas with multiple files.
        if (!(buf->input_offset % MAX_BYTE)) {          // Execute on new line
            buf->o_ptr[COL1_WIDTH + COL2_WIDTH] = '|';
            ft_fill_offset(buf);
        }
        ft_fill_hexa_ascii(buf, MIN(bytesLeft, spaceLeft));
        if (!(buf->input_offset % MAX_BYTE)) {          // We filled up an entire line
            buf->o_ptr += COL2_WIDTH + COL3_WIDTH + 1;
            buf->o_ptr[-2] = '|';
            buf->o_ptr[-1] = '\n';
        }
        if (buf->o_ptr == buf->output + BUF_SIZE)       // Buffer is full
            ft_flush_buffer(buf);
    }
}