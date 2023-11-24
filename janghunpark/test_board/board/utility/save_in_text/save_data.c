#include "save_data.h"

#include "../file_open.h"

#include "read_data.h"

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define BUDDY_PAGE_SIZE             4096


bool write_content_in_file(int file_descriptor, char *content)
{
    int content_length = strlen(content);
    int written_bytes = write(file_descriptor, content, content_length);
    
    printf("written_byte = %d\n", written_bytes);
    printf("content_length = %d\n", content_length);

    if (written_bytes != content_length)
    {
        printf("write() System Call Error!\n");
        return false;
    }

    return true;
}

void adjust_write_contents_from_format(char *contents, board_model *format)
{

    sprintf(contents, "id:%d,title:%s,author:%s,content:%s,\n", 
        format->unique_id, format->title, format->author, format->content);
    printf("contents: %s\n", contents);
}

bool write_data_in_file(board_model *format)
{
    char write_contents[BUDDY_PAGE_SIZE] = { 0 };

    // O_CREAT : 없으면 만듬
    // O_RDWR : Read/Write 모드
    // O_APPEND : 파일 내용의 후속 내용 덧붙이기 가능
    // O_TRUNC : 밀어버리기
    // O_RDONLY : 읽기전용     read : descriptor -> buffer 
                        //   write: buffer -> descriptor
    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-Study-Team2/janghunpark/test_board/board/board_data/board_data.txt", 
            O_CREAT | O_RDWR | O_APPEND, 0644);

    adjust_write_contents_from_format(write_contents, format);

    write_content_in_file(created_file_descriptor, write_contents);

    file_close(created_file_descriptor);
}

void read_board_data_write_from_format(char *contents, read_board_data **format, int i)
{
    sprintf(contents, "id:%d,title:%s,author:%s,content:%s,\n", 
        format[i]->unique_id, format[i]->title, format[i]->author, format[i]->content);
}

bool save_data_after_delete_in_file(read_board_data **post_list)
{
    char contents[BUDDY_PAGE_SIZE] = { 0 };
    int i;

    // O_CREAT : 없으면 만듬
    // O_RDWR : Read/Write 모드
    // O_APPEND : 파일 내용의 후속 내용 덧붙이기 가능
    // O_TRUNC : 밀어버리기
    // O_RDONLY : 읽기전용     read : descriptor -> buffer 
                        //   write: buffer -> descriptor
    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-Study-Team2/janghunpark/test_board/board/board_data/board_data.txt",  
            O_CREAT | O_RDWR | O_TRUNC, 0644);

    for(i = 0; i < test_form_unique_id; i++)
    {
        read_board_data_write_from_format(contents, post_list, i);

        write_content_in_file(created_file_descriptor, contents);
    }

    file_close(created_file_descriptor);
}