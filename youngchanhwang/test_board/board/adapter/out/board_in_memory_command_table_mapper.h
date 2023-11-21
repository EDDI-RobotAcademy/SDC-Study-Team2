#ifndef __BOARD_IN_MEMORY_COMMAND_TABLE_MAPPER_H__
#define __BOARD_IN_MEMORY_COMMAND_TABLE_MAPPER_H__

#include "board_in_memory_command.h"
#include "in_memory/listup_in_memory_command_handler.h"

#define __BOARD_IN_MEMORY_COMMAND_TABLE(number, function_prototype) \
        [number] = function_prototype,

__BOARD_IN_MEMORY_COMMAND_TABLE(BOARD_IN_MEMORY_LISTUP, board_listup)

#endif