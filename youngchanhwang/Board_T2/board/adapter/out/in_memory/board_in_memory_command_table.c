#include <stdio.h>
#include "board_in_memory_command.h"
#include "board_in_memory_command_table.h"

void just_dummy(void)
{
    printf("단순 더미\n");
}

const board_in_memory_call_ptr_t \
    board_in_memory_command_table[BOARD_IN_MEMORY_BUFFER_COUNT] = {
        [0 ... BOARD_IN_MEMORY_BUFFER] = just_dummy,
        #include "board_in_memory_command_table_mapper.h"
};