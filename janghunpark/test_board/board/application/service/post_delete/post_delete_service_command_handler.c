#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../domain/model/board_model.h"

#include "../board_service_command.h"
#include "../board_service_command_table.h"

#include "post_delete_service_command_handler.h"
#include "../../../utility/input_data.h"
#include "../../../utility/save_in_text/read_data.h"
#include "../../../utility/save_in_text/save_data.h"


#define TOTAL_POST_TEXT_LENGTH      4096
#define USER_INPUT                  32

void post_delete_service(void)
{
    char number_input[USER_INPUT] = { 0 };
    unsigned int post_number_by_input;
    read_board_data **post_array;
    
    // 기존 파일에서 게시물 데이터를 읽어서 배열 형성
    post_array = read_file_to_format();

    // 사용자로부터 삭제하고자 하는 게시물 번호를 받아 이를 정수타입으로 전환
    get_unique_post_number(number_input);
    post_number_by_input = atoi(number_input);

    // 사용자가 입력한 정수가 게시물 개수보다 많을시 에러메시지 출력
    while (post_number_by_input > test_form_unique_id)
    {
        printf("해당 게시물이 없습니다. 다시 입력해주세요.\n");
        get_unique_post_number(number_input);
        post_number_by_input = atoi(number_input);
    }

    // 사용자가 입력한 정수가 게시물 고유번호와 일치하는 경우
    // 해당 고유번호의 게시물 아래에 있는 게시글들을 위로 덮어써버린 뒤 
    // '게시물 숫자 -1'을 하고
    // 그만큼의 데이터를 새롭게 읽고 텍스트 파일을 저장할 수 있는 save_data_after_delete_in_file 함수 실행
    if (post_array[post_number_by_input]->unique_id == post_number_by_input)
    {
        for (int i = post_number_by_input; i < test_form_unique_id - 1; i++)
        {
            post_array[i]->title = post_array[i+1]->title;
            post_array[i]->author = post_array[i+1]->author;
            post_array[i]->content = post_array[i+1]->content;            
        }

        test_form_unique_id--;

        save_data_after_delete_in_file(post_array);
        
        printf("%d번 게시물 삭제가 완료되었습니다!\n", post_number_by_input);
    }

    board_service_command_table[POST_MENU_SERVICE_ON_BOARD_EXECUTE]();
}

