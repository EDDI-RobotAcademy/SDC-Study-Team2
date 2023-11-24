#ifndef __BOARD_MODEL_H__
#define __BOARD_MODEL_H__




typedef struct _board_model board_model;

extern unsigned int test_form_unique_id;


struct _board_model
{
    unsigned int unique_id;
    char *title;
    char *author;
    char *content;
};

board_model *init_board_model_object(char *title, char *author, char *content);

#endif