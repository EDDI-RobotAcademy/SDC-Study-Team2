#include "listup_in_memory_command_handler.h"

#include "../../../../adapter/in/api/request/board_read_request.h"

#include "../../../../domain/model/board_model.h"
#include "../../../../utility/save_in_text/read_data.h"

#include <stdio.h>

void board_listup(void)
{
    test_form **test_list;
    test_list = read_file_to_format();
    int i , j ;
    for(i = 0; i < test_form_unique_id ; i++)
    {
        printf("%d. / 제목: %s / 작성자: %s / 내용: %s\n", test_list[i]->unique_id, test_list[i]->title,
                                                            test_list[i]->author, test_list[i]->content);
    }
    

    printf("여기는 리스트 입니다. 일단.\n");
    
}