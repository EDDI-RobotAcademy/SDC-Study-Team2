#include "listup_in_memory_command_handler.h"

#include "../../../../adapter/in/api/request/board_read_request.h"

#include "../../../../domain/model/board_model.h"
#include "../../../../utility/save_in_text/read_data.h"

#include <stdio.h>

void board_listup(void)
{
    read_board_data **post_list;
    post_list = read_file_to_format();
    int i , j ;
    for(i = 0; i < test_form_unique_id ; i++)
    {
        printf("%d. / 제목: %s / 작성자: %s\n", post_list[i]->unique_id, post_list[i]->title,
                                                            post_list[i]->author);
    }
    
    
}