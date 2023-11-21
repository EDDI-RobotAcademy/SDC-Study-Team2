#include <stdio.h>

#include "adaptor/in/api/request/board_operation_request.h"
#include "utility/ui/console/user_keyboard_input.h"

int main (void)
{
	post_info *test_post = init_post_info_by_write_command();
    
    printf("게시물의 형태는 다음과 같습니다.\n");
    printf("%s,\n,%s\n,%s\n", test_post->post_title, test_post->post_writer, test_post->post_contents);

    return 0;
}