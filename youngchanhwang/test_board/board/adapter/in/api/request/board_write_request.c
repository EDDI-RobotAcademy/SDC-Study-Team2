#include "board_write_request.h"

#include "../../../../domain/model/board_model.h"
#include "../../../../utility/input_data.h"

board_model write_request(void)
{
    board_model *post_write_save;
    char *title = { 0 };
    char *author = { 0 };
    char *content = { 0 };
    get_title_keyboard_input(title);
    get_author_keyboard_input(author);
    get_contents_keyboard_input(content);

    post_write_save = init_board_model_object(&title, &author, &content);


    return *post_write_save;
}