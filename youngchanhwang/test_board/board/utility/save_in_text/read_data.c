
#include "read_data.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUDDY_PAGE_SIZE         4096


void read_content_from_file(int file_descriptor, char *read_content)
{
    read(file_descriptor, read_content, 4096);
}

int file_total_length (int file_descriptor)
{
    // lseek의 리턴 값은 두 번째 인자부터 3번째 인자까지 file pointer를 이동한 숫자
    return lseek(file_descriptor, 0, SEEK_END);
}

test_form **read_file_to_format(void)
{
    char read_contents[BUDDY_PAGE_SIZE] = { 0 };
    int object_count;
    int total_length;

    test_form **test_format_array;

    // O_RDONLY: 읽기 전용
    int created_file_descriptor = file_open(
        "/home/eddi/study_first/SDC-Study-Team2/"
        "youngchanhwang/test_board/board/board_data/board_data.txt", 
            O_RDONLY, 0644);

    //read_content_from_file_and_print(created_file_descriptor, read_contents);
    read_content_from_file(created_file_descriptor, read_contents);
    printf("read_contents: %s\n", read_contents);

    // total_length = file_total_length(created_file_descriptor);
    file_close(created_file_descriptor);

    // object_count = find_enter_line_for_format_count(read_contents, total_length);
    // test_format_array = init_test_form_array(object_count);
    // printf("object_count: %d\n", object_count);

    // test_format_array = set_test_form_with_read_contents(test_format_array, object_count, read_contents);
    // printf("test_format_array: 0x%x\n", test_format_array);
}