#include "input_data.h"

#include <unistd.h>


void get_number_keyboard_input(char *number_keyboard_input)
{
    read(0, number_keyboard_input, MAX_NUMBER_KEYBOARD_INPUT);
}


void get_title_keyboard_input(char *title_keyboard_input)
{
    read(0, title_keyboard_input, MAX_TITLE_KEYBOARD_INPUT);
}