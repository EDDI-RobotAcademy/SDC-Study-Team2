#include "board_read_request.h"
#include "../../../../utility/save_in_text/read_data.h"

#include "../../../../utility/input_data.h"
#include <stdlib.h>


read_board_data read_request(void)
{
        
}

int read_request_unique_id(void)
{
    int tmp_unique_id;
    char number_input[MAX_NUMBER_KEYBOARD_INPUT] = { 0 };
    get_unique_id_keyboard_input(number_input);

    return tmp_unique_id = atoi(number_input);
}