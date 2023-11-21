#include "first_screen_input.h"
#include "user_keyboard_input.h"

#include <stdio.h>
#include <stdlib.h>


#include "../../../application/service/board_service_command.h"
#include "../../../application/service/post_write/post_write_service_command_handler.h"
#include "../../../application/service/board_service_command_table.h"


#define MAX_OUTPUT_MESSAGE          128


void first_screen_input()
{
    char keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char output_message[MAX_OUTPUT_MESSAGE] = {
        "0번. 게시물 작성\n"
        "1번. 게시물 삭제\n"
        "2번. 게시물 읽기\n"
        "3번. 게시물 수정\n"
    };

    get_user_keyboard_input_with_message(output_message,keyboard_input);
    printf("사용자 입력: %d\n", atoi(keyboard_input));

    int keyboard_input_int = atoi(keyboard_input);
    
    switch (keyboard_input_int)
    {
    case POST_WRITE_SERVICE_ON_BOARD_EXECUTE:
        printf("0번작동\n");
        board_service_command_table[POST_WRITE_SERVICE_ON_BOARD_EXECUTE]();
        break;
    
    default:
        printf("잘못 입력 하셨습니다. 다시 입력해 주세요\n");
        first_screen_input();
        break;
    }
}
