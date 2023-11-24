#include "input_data.h"

#include <unistd.h>
#include <string.h>
// File Descriptor(파일 디스크립터)
// 0번 = 표준 입력
// 1번 = 표준 출력
// 2번 = 표준 에러

// Unix 핵심 철학: 모든 것은 파일이다.


// 사용자 입력 받기
void get_number_keyboard_input(char *number_keyboard_input)
{
    write(1, "이용하실 기능을 선택\n", strlen("이용하실 기능을 선택\n"));
    read(0, number_keyboard_input, MAX_NUMBER_KEYBOARD_INPUT);
}


void get_title_keyboard_input(char *title_keyboard_input)
{
    write(1, "제목을 입력하세요.\n", strlen("제목을 입력하세요.\n"));
    read(0, title_keyboard_input, MAX_TITLE_KEYBOARD_INPUT);
}


void get_author_keyboard_input(char *author_keyboard_input)
{
    write(1, "작성자명을 입력하세요.\n", strlen("작성자명을 입력하세요.\n"));
    read(0, author_keyboard_input, MAX_AUTHOR_KEYBOARD_INPUT);
}
void get_contents_keyboard_input(char *contents_keyboard_input)
{
    write(1, "내용을 입력하세요.\n", strlen("내용을 입력하세요.\n"));
    read(0, contents_keyboard_input, MAX_CONTENTS_KEYBOARD_INPUT);
}

void get_unique_id_keyboard_input(char* unique_id_keyboard_input)
{
    write(1, "수정하실 게시물의 번호를 입력하세요.\n", strlen("수정하실 게시물의 번호를 입력하세요.\n"));
    read(0, unique_id_keyboard_input, MAX_NUMBER_KEYBOARD_INPUT);
}