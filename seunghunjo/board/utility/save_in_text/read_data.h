#ifndef __READ_DATA_H__
#define __READ_DATA_H__



typedef struct _read_board_data read_board_data;

struct _read_board_data
{
    int unique_id;
    char *title;
    char *author;
    char *content;
};

read_board_data **read_file_to_format(void);

#endif