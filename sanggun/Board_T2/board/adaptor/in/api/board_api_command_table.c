#include <stdio.h>

#include "board_api_command.h"
#include "board_api_command_table.h"

void not_implemented(void)
{
    printf("무엇을 해야하나?\n");
}

const board_api_call_ptr_t \
    board_api_command_table[BOARD_CALL_BUFFER_COUNT] = {
        [0 ... BOARD_CALL_BUFFER] = not_implemented,
        #include "board_api_command_table_mapper.h"
};