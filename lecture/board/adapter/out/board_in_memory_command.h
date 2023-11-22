#ifndef __BOARD_IN_MEMORY_COMMAND_H__
#define __BOARD_IN_MEMORY_COMMAND_H__

enum board_in_memory_command
{
    BOARD_IN_MEMORY_LISTUP,
    BOARD_IN_MEMORY_END
};

#define BOARD_IN_MEMORY_BUFFER_COUNT         (BOARD_IN_MEMORY_END)
#define BOARD_IN_MEMORY_BUFFER               ((BOARD_IN_MEMORY_END) - 1)

#endif
