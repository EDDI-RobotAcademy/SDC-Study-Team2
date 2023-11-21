#include "post_menu_service_command_handler.h"
#include "../../../utility/input_data.h"

#include "../../../adapter/out/board_in_memory_command.h"
#include "../../../adapter/out/in_memory/listup_in_memory_command_handler.h"
#include "../../../adapter/out/board_in_memory_command_table.h"


#include <stdio.h>
#include <string.h>

#define MAX_MENU_NUM_SELECT            5
#define MAX_MENU_NUM                   6
void post_menu_service(void)
{
    char number_input[MAX_NUMBER_KEYBOARD_INPUT] = { 0 };
    char *post_menu_list[MAX_MENU_NUM] = {
        "0. 게시글 목록 보기",
        "1. 게시글 내용 보기",
        "2. 게시글 작성 하기",
        "3. 게시글 수정 하기",
        "4. 게시글 삭제 하기",
        "5. 게시판 종료 하기"
    };
    unsigned int i; 
    int select_num;

    for(i = 0; i < MAX_MENU_NUM ; i ++)
    {
        printf("%s\n" ,post_menu_list[i]);
    }

    board_in_memory_command_table[0]();

    get_number_keyboard_input(number_input);
    select_num = *number_input - '0';
    i = select_num;
    while(i > MAX_MENU_NUM_SELECT)
    {
        printf("0 ~ 5 중에 선택 해주세요.\n");
        get_number_keyboard_input(number_input);
        select_num = *number_input - '0';
        i = select_num;
    }
    printf("%d번을 선택하셨습니다.\n", select_num);


    // board_service_command_table[select_num]();


}