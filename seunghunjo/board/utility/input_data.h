#ifndef __INPUT_DATA_H__
#define __INPUT_DATA_H__


#define MAX_NUMBER_KEYBOARD_INPUT       32
#define MAX_TITLE_KEYBOARD_INPUT        32
#define MAX_AUTHOR_KEYBOARD_INPUT       32
#define MAX_CONTENTS_KEYBOARD_INPUT     4096

void get_number_keyboard_input(char *number_keyboard_input);


void get_title_keyboard_input(char *title_keyboard_input);
void get_author_keyboard_input(char *author_keyboard_input);
void get_contents_keyboard_input(char *contents_keyboard_input);

void get_unique_id_keyboard_input(char* unique_id_keyboard_input);

#endif