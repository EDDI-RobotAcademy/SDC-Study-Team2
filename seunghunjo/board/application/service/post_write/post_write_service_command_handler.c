#include "post_write_service_command_handler.h"
#include "../../../utility/input_data.h"
#include "../../../domain/model/board_model.h"
#include "../../../adapter/in/api/request/board_write_request.h"

#include "../../../utility/save_in_text/save_data.h"


#include "../board_service_command.h"
#include "../board_service_command_table.h"


#include <stdio.h>
#include <stdlib.h>


void post_write_service(void)
{
    board_model *post_write_request;
    post_write_request = (board_model*)malloc(sizeof(board_model));
    *post_write_request = write_request();

    // printf("%d\n%s%s%s\n",post_write_request->unique_id, post_write_request->title, post_write_request->author, post_write_request->content);
    
    write_data_in_file(post_write_request);


    board_service_command_table[POST_MENU_SERVICE_ON_BOARD_EXECUTE]();
}
