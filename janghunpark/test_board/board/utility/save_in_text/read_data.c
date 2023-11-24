
#include "read_data.h"
#include "../file_open.h"
#include "../../domain/model/board_model.h"


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

read_board_data **init_test_form_array(int count)
{
    read_board_data **tmp_format = (read_board_data **)malloc(sizeof(read_board_data *) * count);

    return tmp_format;
}

read_board_data *init_test_form_with_id(int id, char *title, char *author, char *content)
{
    read_board_data *tmp_form = (read_board_data *)malloc(sizeof(read_board_data));
    int title_length = strlen(title) + 1;
    int author_length = strlen(author) + 1;
    int content_length = strlen(content) + 1;

    tmp_form->unique_id = id;

    tmp_form->title = (char *)malloc(sizeof(char) * title_length);
    strncpy(tmp_form->title, title, title_length);

    tmp_form->author = (char *)malloc(sizeof(char) * author_length);
    strncpy(tmp_form->author, author, author_length);

    tmp_form->content =
        (char *)malloc(sizeof(char) * content_length);
    strncpy(tmp_form->content, content, content_length);

    return tmp_form;
}


int find_enter_line_for_format_count(char *buffer, int total_length)
{
    int i;
    int count = 0;

    for (i = 0; i < total_length; i++)
    {
        if (!strncmp(&buffer[i], "\n", 1))
        {
            count++;
        }
    }

    return count;
}

read_board_data **set_test_form_with_read_contents(
    read_board_data **test_format_array, int object_count, char *read_contents)
{
    int i;
    int field_count = 0;
    char title[32];
    char author[32];
    char content[4096];
    unsigned int unique_id;

    int start, finish;
    bool started = false;
    int read_contents_length = strlen(read_contents);

    // 읽은 내용을 1 바이트씩 순회
    for (i = 0; i < read_contents_length; i++)
    {
        // ":" 찾기
        // 왜 찾는가 ?
        // format이 아래와 같으니까
        // id:1,major:시고르원조,age:20,introduction:낵아 시고르원조다!,
        if (!started && !strncmp(&read_contents[i], ":", 1))
        {
            start = i;
            started = true;
        }

        // "," 찾기
        if (started && !strncmp(&read_contents[i], ",", 1))
        {
            finish = i;
            started = false;
            // printf("start = %d, finish = %d\n", start, finish);

            // ":" 과 "," 사이의 값이 객체에 배치해야하는 정보임
            if (field_count % 4 == 0)
            {
                char tmp_str[32] = { 0 };
                strncpy(tmp_str, &read_contents[start + 1], finish - start - 1);
                unique_id = atoi(tmp_str);
                // printf("unique_id = %d\n", unique_id);
            }

            if (field_count % 4 == 1)
            {
                char tmp_str[32] = { 0 };
                // major 배열이 기존 정보를 유지하고 있을 가능성이 있으므로
                // 전체 배열을 0 으로 초기화 시키는 작업임
                memset(title, 0x00, 32);
                strncpy(title, &read_contents[start + 1], finish - start - 1);
                // printf("title = %s\n", title);
            }

            if (field_count % 4 == 2)
            {
                memset(author, 0x00, 32);
                strncpy(author, &read_contents[start + 1], finish - start - 1);
                // printf("author = %s\n", author);
            }

            if (field_count % 4 == 3)
            {
                char tmp_str[128] = { 0 };
                memset(content, 0x00, 128);
                strncpy(content, &read_contents[start + 1], finish - start - 1);
                // printf("content: %s\n", content);

                test_format_array[field_count / 4] = 
                init_test_form_with_id(unique_id, title, author, content);
            }

            // if (field_count % 4 == 0) {
            //     test_format_array[field_count++ / 4] 
            // }

            field_count++;
        }
    }

    return test_format_array;
}


read_board_data **read_file_to_format(void)
{
    char read_contents[BUDDY_PAGE_SIZE] = { 0 };
    int object_count;
    int total_length;

    read_board_data **test_format_array;

    // O_RDONLY: 읽기 전용
    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-Study-Team2/janghunpark/test_board/board/board_data/board_data.txt", 
            O_RDONLY, 0644);

    //read_content_from_file_and_print(created_file_descriptor, read_contents);
    read_content_from_file(created_file_descriptor, read_contents);
    // printf("read_contents: %s\n", read_contents);

    total_length = file_total_length(created_file_descriptor);
    file_close(created_file_descriptor);

    object_count = find_enter_line_for_format_count(read_contents, total_length);
    test_format_array = init_test_form_array(object_count);
    test_form_unique_id = object_count;
    // printf("object_count: %d\n", object_count);

    test_format_array = set_test_form_with_read_contents(test_format_array, object_count, read_contents);
    // printf("test_format_array: 0x%x\n", test_format_array);
    return test_format_array;
}