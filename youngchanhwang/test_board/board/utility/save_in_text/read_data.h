#ifndef __READ_DATA_H__
#define __READ_DATA_H__



typedef struct _test_form test_form;

struct _test_form
{
    int unique_id;
    char *title;
    char *author;
    char *content;
};

test_form **read_file_to_format(void);

#endif