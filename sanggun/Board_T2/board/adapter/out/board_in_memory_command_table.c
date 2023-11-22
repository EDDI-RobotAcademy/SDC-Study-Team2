#include <stdio.h>
#include "board_in_memory_command.h"
#include "in_memory/listup/listup_in_memory_command_handler.h"
#include "board_in_memory_command_table.h"


void not_implemented_in_memory(void)
{
    printf("아직 구현되지 않은 기능입니다!\n");
}
const board_in_memory_call_ptr_t \
    board_in_memory_command_table[BOARD_IN_MEMORY_BUFFER_COUNT] = {
        [0 ... BOARD_IN_MEMORY_BUFFER] = not_implemented_in_memory,
        #include "board_in_memory_command_table_mapper.h"
};