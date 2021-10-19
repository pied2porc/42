#include "ft_door.h"
#include <stdlib.h>

int main()
{
    t_door door;

    open_door(&door);
    if (is_door_close(&door))
        open_door(&door);
    if (is_door_open(&door))
        close_door(&door);
    if (door.state == OPEN)
        close_door(&door);
    return EXIT_SUCCESS;
}