#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../../application/service/board_service_command.h"
#include "post_read_service_command_handler.h"
#include "../../../adapter/out/in_memory/listup/listup_in_memory_command_handler.h"
#include "../../../utility/save_in_text/read_data.h"
#include "../../../domain/model/board_model.h"
#include "../../../utility/input_data.h"
#include "../../../application/service/post_menu/post_menu_service_command_handler.h"
#include "../../../application/service/board_service_command_table.h"

#define MAX_USER_INPUT      32
//=> 이거는 선택? 핸들러 아니야
void post_read_service(void)
{
    test_form **test_list;
    test_list = read_file_to_format();
    char user_keyboard_input[MAX_USER_INPUT] = { 0 };
    int post_number;
    int for_post_list;
    

    get_post_read_keyboard_input(user_keyboard_input); // 숫자 하나 받기
    post_number = atoi(user_keyboard_input);
    printf("%d번 글의 내용은 아래와 같습니다!\n%s\n",test_list[post_number]->unique_id, test_list[post_number]->content);

    board_service_command_table[POST_MENU_SERVICE_ON_BOARD_EXECUTE]();
}

