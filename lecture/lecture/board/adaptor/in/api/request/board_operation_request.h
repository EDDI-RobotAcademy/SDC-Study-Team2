#ifndef __BOARD_OPERATION_REQUEST__
#define __BOARD_OPERATION_REQUEST__

#include "../../../../domain/model/board_model.h"

// post에 들어갈 '정보 집합체'
typedef struct _board_operation_request post_info;

struct _board_operation_request
{
    unsigned int post_number;
    char *post_title;
    char *post_writer;
    char *post_contents;
};

post_info *init_post_info_by_write_command(void);
void post_formation_by_request(post_info *post_from_request, char *title, char *writer, char *contents);

#endif