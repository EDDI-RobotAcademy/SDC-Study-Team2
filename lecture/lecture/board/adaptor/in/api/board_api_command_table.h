#ifndef __BOARD_API_COMMAND_TABLE_H__
#define __BOARD_API_COMMAND_TABLE_H__

#include "board_api_command.h"

typedef void (* board_api_call_ptr_t) (void);

void not_implemented (void);

extern const board_api_call_ptr_t \
    board_api_command_table[BOARD_CALL_BUFFER_COUNT];

#endif