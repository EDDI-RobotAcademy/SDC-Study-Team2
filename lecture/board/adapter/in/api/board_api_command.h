#ifndef __BOARD_API_COMMAND_H__
#define __BOARD_API_COMMAND_H__

enum board_api_command
{
    BOARD_API_OPERATION,
    BOARD_API_END
};

#define BOARD_API_BUFFER_COUNT         (BOARD_API_END)
#define BOARD_API_BUFFER               ((BOARD_API_END) - 1)

#endif
