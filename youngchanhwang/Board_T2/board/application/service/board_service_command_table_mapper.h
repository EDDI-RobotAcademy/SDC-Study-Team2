#ifndef __BOARD_SERVICE_COMMAND_TABLE_MAPPER_H__
#define __BOARD_SERVICE_COMMAND_TABLE_MAPPER_H__

#include "board_service_command.h"
#include "post_menu/post_menu_service_command_handler.h"

#define __BOARD_SERVICE_COMMAND_TABLE(number, function_prototype) \
        [number] = function_prototype,

__BOARD_SERVICE_COMMAND_TABLE(POST_MENU_SERVICE_ON_BOARD_EXECUTE, post_menu_service)


#endif