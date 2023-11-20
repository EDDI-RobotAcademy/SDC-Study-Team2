#include "post_menu_service_command_handler.h"
#include "../../../utility/input_data.h"


#include <stdio.h>
#include <string.h>


void post_menu_service(void)
{
    char number_input[MAX_NUMBER_KEYBOARD_INPUT] = { 0 };
    int i, select_num;
    printf("    0. 게시글 목록 보기\n\
    1. 게시글 내용 보기\n\
    2. 게시글 작성 하기\n\
    3. 게시글 수정 하기\n\
    4. 게시글 삭제 하기\n\
    5. 종료\n");


    get_number_keyboard_input(number_input);
    select_num = *number_input - '0';

    
    printf("%d번을 선택하셨습니다.", select_num);
    
    // board_service_command_table[select_num]();


}