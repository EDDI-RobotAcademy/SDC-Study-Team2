#include <stdio.h>
#include "board_api_command.h"
#include "operation/board_operation_api_command_handler.h"
#include "board_api_command_table.h"

void not_implemented(void)
{
    printf("아직 구현되지 않은 기능입니다!\n");
}
const board_api_call_ptr_t \
    board_api_command_table[BOARD_API_BUFFER_COUNT] = {
        [0 ... BOARD_API_BUFFER] = not_implemented,
        #include "board_api_command_table_mapper.h"
};