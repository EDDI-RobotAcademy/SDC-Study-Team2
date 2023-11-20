#ifndef __BOARD_OPERATION_REQUEST__
#define __BOARD_OPERATION_REQUEST__

#include "../../../../domain/model/board_model.h"

// post에 들어갈 '정보 집합체'
// 게시판 동작 요청에 따라 형성되는 구조체는
// 결국 입력 받거나 읽어올 게시물의 정보이므로 아래와 같이 명명합니다.
// '동작', 그로부터 얻는 구조체의 정확한 '의미'를 구분하기 위함이었습니다.
typedef struct _board_operation_request post_info;

struct _board_operation_request
{
    unsigned int post_number;
    char *post_title;
    char *post_writer;
    char *post_contents;
};

post_info *init_post_info_by_write_command(void);
void post_info_title_from_request(post_info *post_from_request, char *title);
void post_info_writer_from_request(post_info *post_from_request, char *writer);
void post_info_contents_from_request(post_info *post_from_request, char *contents);

#endif