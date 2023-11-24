#include "board_model.h"

#include <stdio.h>
#include <stdlib.h>


unsigned int test_form_unique_id;

int increment_test_form_unique_id(void)
{
    return test_form_unique_id++;
}

board_model *init_board_model_object(char *title, char *author, char *content)
{
    board_model *tmp_board = (board_model *)malloc(sizeof(board_model));
    // input에서 \n까지 포함된 문자열이 저장되어서 \n을 제거하기 위한 -1
    int title_length = strlen(title) - 1;
    int author_length = strlen(author) - 1;
    int content_length = strlen(content) - 1;

    tmp_board->unique_id = increment_test_form_unique_id();
    
    tmp_board->title =
        (char *)malloc(sizeof(char) * title_length);
    strncpy(tmp_board->title , title , title_length);

    tmp_board->author = 
        (char *)malloc(sizeof(char) * author_length);
    strncpy(tmp_board->author,author,author_length);

    tmp_board->content = 
        (char *)malloc(sizeof(char) * content_length);
    strncpy(tmp_board->content,content,content_length);



    return tmp_board;

}