#ifndef __SAVE_DATA_H__
#define __SAVE_DATA_H__

#include <stdbool.h>

#include "../../domain/model/board_model.h"
#include "read_data.h"

bool write_content_in_file(int file_descriptor, char *content);
void adjust_write_contents_from_format(char *contents, board_model *format);
bool write_data_in_file(board_model *);

void read_board_data_write_from_format(char *contents, read_board_data **format, int i);
bool write_data_in_file_editver(read_board_data **post_list);


#endif