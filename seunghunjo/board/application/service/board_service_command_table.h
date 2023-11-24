#ifndef __BOARD_SERVICE_COMMAND_TABLE_H__
#define __BOARD_SERVICE_COMMAND_TABLE_H__

#include "board_service_command.h"

typedef void (* board_service_call_ptr_t) (void);

void just_dummy(void);


extern const board_service_call_ptr_t 
    board_service_command_table[SERVICE_ON_BOARD_EXECUTE_BUFFER_COUNT];

#endif
