#ifndef __BOARD_API_COMMAND_TABLE_MAPPER_H__
#define __BOARD_API_COMMAND_TABLE_MAPPER_H__

#include "board_api_command.h"
#include "operation/board_operation_api_command_handler.h"
#include "request/board_operation_request.h"


#include "board_api_command_table.h"

#define __BOARD_API_COMMAND_TABLE(number, function_prototype) \
    [number] = function_prototype,

__BOARD_API_COMMAND_TABLE(BOARD_API_OPERATION, board_operation);
__BOARD_API_COMMAND_TABLE(BOARD_API_OPERATION_REQUEST,init_post_info_by_write_command);

#endif