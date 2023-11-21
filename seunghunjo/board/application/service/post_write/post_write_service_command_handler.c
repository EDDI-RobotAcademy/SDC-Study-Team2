#include "post_write_service_command_handler.h"
#include "../../../adaptor/in/api/board_api_command.h"
#include "../../../adaptor/in/api/board_api_command_table.h"
#include "../../../adaptor/in/api/request/board_operation_request.h"

#include <stdio.h>

void post_write_handler(void)
{
    post_info *test_post = board_api_command_table[BOARD_API_OPERATION_REQUEST];

    printf("게시물의 형태는 다음과 같습니다.\n");
    printf("%s,\n%s,\n%s,\n", test_post->post_title, test_post->post_writer, test_post->post_contents);
}