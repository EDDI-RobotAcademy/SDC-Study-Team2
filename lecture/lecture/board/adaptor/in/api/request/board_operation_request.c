#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "board_operation_request.h"
#include "../../../../utility/ui/console/user_keyboard_input.h"

// 데이터를 게시글 형태로 setting하는 것

// board service command 번호를 입력받은 뒤
// post 정보를 '입력'받거나 '출력'할 수 있는 tmp_post_info 객체를 생성
// 예를 들어 게시물 생성 명령을 입력받은 경우 
post_info *init_post_info_by_write_command(void)
{
    // 이 부분은 사용자로부터 입력 받거나 해야 함
    char keyboard_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    post_info *tmp_post_info = (post_info *)malloc(sizeof(post_info));

    printf("제목을 입력하세요.\n");
    get_user_keyboard_input(keyboard_input_from_user);
    post_info_title_from_request(tmp_post_info, keyboard_input_from_user);
    
    printf("작성자를 입력하세요.\n");
    get_user_keyboard_input(keyboard_input_from_user);
    post_info_writer_from_request(tmp_post_info, keyboard_input_from_user);
    
    printf("내용을 입력하세요.\n");
    get_user_keyboard_input(keyboard_input_from_user);
    post_info_contents_from_request(tmp_post_info, keyboard_input_from_user);
    
    return tmp_post_info;
}

void post_info_title_from_request(post_info *post_from_request, char *title)
{
    int title_length = strlen(title) + 1;
    post_from_request->post_title = (char *)malloc(sizeof(char) * title_length);
    strncpy(post_from_request->post_title, title, title_length);
}

void post_info_writer_from_request(post_info *post_from_request, char *writer)
{
    int writer_length = strlen(writer) + 1;
    post_from_request->post_writer = (char *)malloc(sizeof(char) * writer_length);
    strncpy(post_from_request->post_writer, writer, writer_length);
}

void post_info_contents_from_request(post_info *post_from_request, char *contents)
{
    int contents_length = strlen(contents) + 1;
    post_from_request->post_contents = (char *)malloc(sizeof(char) * contents_length);
    strncpy(post_from_request->post_contents, contents, contents_length);
}