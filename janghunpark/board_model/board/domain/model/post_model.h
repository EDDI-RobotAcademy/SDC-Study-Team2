#ifndef __POST_MODEL_H__
#define __POST_MODEL_H__

#define MAX_TITLE_LENGTH            128
#define MAX_WRITTER_LENGTH          64
#define MAX_CONTENTS_LENGTH         4096

extern int unique_count;

typedef struct _post_model post_model;

struct _post_model
{
    unsigned int unique_id;
    char *title;
    char *writter;
    char *contents;
};

post_model *init_post_model_object(void);
post_model *put_data_into_post_model(post_model *test_post, unsigned int number, char *title, char *writter, char *contents);
void print_post_model(post_model *test_post);

#endif