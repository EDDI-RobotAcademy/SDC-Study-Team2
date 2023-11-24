#include "post_edit_service_command_handler.h"
#include "../../../adapter/in/api/request/board_read_request.h"
#include "../../../adapter/in/api/request/board_write_request.h"

#include "../../../domain/model/board_model.h"
#include "../../../utility/save_in_text/read_data.h"
#include "../../../utility/input_data.h"
#include "../../../utility/save_in_text/save_data.h"

#include "../board_service_command.h"
#include "../board_service_command_table.h"


#include <stdio.h>
#include <stdlib.h>


void post_edit_service(void)
{
    printf("일단 편집\n");
    int choice_unique_id = read_request_unique_id();

    read_board_data **post_list;
    post_list = read_file_to_format();
    board_model *post_write_request;
    post_write_request = (board_model*)malloc(sizeof(board_model));
    *post_write_request = write_request();

    post_list[choice_unique_id]->unique_id = choice_unique_id;
    post_list[choice_unique_id]->author = post_write_request->author;
    post_list[choice_unique_id]->title = post_write_request->title;
    post_list[choice_unique_id]->content = post_write_request->content;
    test_form_unique_id--;

    write_data_in_file_editver(post_list);


    board_service_command_table[POST_MENU_SERVICE_ON_BOARD_EXECUTE]();
}