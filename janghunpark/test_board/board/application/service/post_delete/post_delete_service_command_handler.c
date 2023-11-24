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
    read_board_data **new_post_array;
    
    post_array = read_file_to_format();

    get_unique_post_number(number_input);
    post_number_by_input = atoi(number_input);

    while (post_number_by_input > test_form_unique_id)
    {
        printf("해당 게시물이 없습니다. 다시 입력해주세요.\n");
        get_unique_post_number(number_input);
        post_number_by_input = atoi(number_input);
    }

    if (post_array[post_number_by_input]->unique_id == post_number_by_input)
    {
        // 1. 파일 밀기
        // 2. 입력받은 게시물 아래
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

