#ifndef __BOARD_IN_MEMORY_COMMAND_TABLE_H__
#define __BOARD_IN_MEMORY_COMMAND_TABLE_H__

#include "board_in_memory_command.h"

typedef void (* board_in_memory_call_ptr_t) (void);

extern const board_in_memory_call_ptr_t 
    board_in_memory_command_table[BOARD_IN_MEMORY_BUFFER_COUNT];

#endif
