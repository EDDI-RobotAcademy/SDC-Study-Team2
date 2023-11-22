#include "board_write_request.h"

#include "../../../../domain/model/board_model.h"
#include "../../../../utility/input_data.h"

board_model write_request(void)
{
    board_model *post_write_save;
    char get_title[MAX_TITLE_KEYBOARD_INPUT] = { 0 };
    char get_author[MAX_AUTHOR_KEYBOARD_INPUT] = { 0 };
    char get_content[MAX_CONTENTS_KEYBOARD_INPUT] = { 0 };

    get_title_keyboard_input(get_title);
    get_author_keyboard_input(get_author);
    get_contents_keyboard_input(get_content);

    post_write_save = init_board_model_object(get_title, get_author, get_content);


    return *post_write_save;
}