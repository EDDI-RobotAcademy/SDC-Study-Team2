#include <stdio.h>

#include "../../../../domain/model/board_model.h"

#include "board_operation_api_command_handler.h"

#include "../../../../application/service/board_service_command.h"
#include "../../../../application/service/board_service_command_table.h"
#include "../../../../application/service/post_listup/post_listup_service_command_handler.h"
#include "../../../../application/service/post_write/post_write_service_command_handler.h"
#include "../../../../application/service/post_read/post_read_service_command_handler.h"
#include "../../../../application/service/post_edit/post_edit_service_command_handler.h"
#include "../../../../application/service/post_delete/post_delete_service_command_handler.h"

#include "../request/board_operation_request.h"

void board_operation(void)
{
    post_info *post_inforamtion;
    int command_number = get_command_number_from_user(); // int type의 command index를 받는 함수

    // 아래 정보들을 입력받는 함수 ; get_info 혹은 read_info
    char *title;
    char *writer;
    char *contents;

    post_inforamtion = init_post_info_by_write_command(); // 괄호 안에 info에 대한 함수를 받아 post로 도출

    printf("입력하신 기능을 수행합니다!\n");

    // post에 대해 사용자가 입력한 명령 실행
    board_service_command_table[SERVICE_ON_BOARD_EXECUTE_BUFFER_COUNT];
}