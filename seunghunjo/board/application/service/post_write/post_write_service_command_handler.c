#include "post_write_service_command_handler.h"
#include "../../../utility/input_data.h"
#include "../../../domain/model/board_model.h"
#include "../../../adapter/in/api/request/board_write_request.h"

#include <stdio.h>


void post_write_service(void)
{
    board_model *post_write_request;
    *post_write_request = write_request();

    printf("%d\n%s%s%s\n",post_write_request->unique_id, post_write_request->title, post_write_request->author, post_write_request->content);
    
}
