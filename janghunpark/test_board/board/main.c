#include <stdio.h>

#include "utility/input_data.h"

#include "application/service/board_service_command.h"

#include "application/service/post_menu/post_menu_service_command_handler.h"

#include "application/service/board_service_command_table.h"

#include "adapter/in/api/board_api_command.h"
#include "adapter/in/api/operation/board_operation_api_command_handler.h"
#include "adapter/in/api/board_api_command_table.h"

int main (void)
{
    board_api_command_table[BOARD_API_OPERATION]();

    return 0;
}