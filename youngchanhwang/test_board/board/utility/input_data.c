#include "input_data.h"

#include <unistd.h>

// File Descriptor(파일 디스크립터)
// 0번 = 표준 입력
// 1번 = 표준 출력
// 2번 = 표준 에러

// Unix 핵심 철학: 모든 것은 파일이다.


// 사용자 입력 받기
void get_number_keyboard_input(char *number_keyboard_input)
{
    read(0, number_keyboard_input, MAX_NUMBER_KEYBOARD_INPUT);
}


void get_title_keyboard_input(char *title_keyboard_input)
{
    read(0, title_keyboard_input, MAX_TITLE_KEYBOARD_INPUT);
}

