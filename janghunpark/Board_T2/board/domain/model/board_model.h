#ifndef __BOARD_MODEL_H__
#define __BOARD_MODEL_H__

typedef struct _board_model board_model;

struct _board_model
{
    unsigned int command_number;
    char *command_name;
};

#endif