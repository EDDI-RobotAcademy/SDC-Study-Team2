#ifndef __BOARD_READ_REQUEST_H__
#define __BOARD_READ_REQUEST_H__

#include "../../../../utility/save_in_text/read_data.h"
#include "../../../../domain/model/board_model.h"

#define MAX_UNIQUE_ID                   4090


read_board_data read_request(void);

int read_request_unique_id(void);


#endif