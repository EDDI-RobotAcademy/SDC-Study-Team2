#include <stdio.h>
#include "board_service_command.h"
#include "board_service_command_table.h"

void just_dummy(void)
{
    printf("단순 더미\n");
}

const board_service_call_ptr_t \
    board_service_command_table[SERVICE_ON_BOARD_EXECUTE_BUFFER_COUNT] = {
        [0 ... SERVICE_ON_BOARD_EXECUTE_BUFFER] = just_dummy,
        #include "board_service_command_table_mapper.h"
};