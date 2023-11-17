#include <stdio.h>

#include "board/domain/model/post_model.h"

int main (void)
{
    post_model *test_post;
    unsigned int id = 1;
    char post_title[MAX_TITLE_LENGTH] = { "hello" };
    char post_writter[MAX_WRITTER_LENGTH] = { "janghun" };
    char post_contents[MAX_CONTENTS_LENGTH] = { "This is the first post!" };

    // 게시물 객체 생성
    test_post = init_post_model_object();

    // 데이터 입력 --> 나중에 '쓰기' 라는 기능 도메인에 들어갈 세부사항
    put_data_into_post_model(test_post, id, post_title, post_writter, post_contents);

    // 게시물 출력
    print_post_model(test_post);

    return 0;
}