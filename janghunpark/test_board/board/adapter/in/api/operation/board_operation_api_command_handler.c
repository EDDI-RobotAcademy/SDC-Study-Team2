
#include "../../../../application/service/board_service_command.h"
#include "board_operation_api_command_handler.h"
#include "../../../../application/service/board_service_command_table.h"


#include <stdio.h>

void board_operation(void)
{
    printf("게시판이 작동합니다. 명령을 선택하세요.\n");

    board_service_command_table[POST_MENU_SERVICE_ON_BOARD_EXECUTE]();
}