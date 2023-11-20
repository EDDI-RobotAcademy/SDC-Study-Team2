#include "board_operation_api_command_handler.h"

#include "../../../../application/service/board_service_command.h"
#include "../../../../application/service/board_service_command_table.h"

#include <stdio.h>

void board_operation(void)
{
    printf("operation\n");

    board_service_command_table[0]();

}