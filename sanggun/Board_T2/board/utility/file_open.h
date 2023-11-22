#ifndef __FILE_OPEN_H__
#define __FILE_OPEN_H__

#define ERROR           (-1)

int file_open(char *filename, int option, unsigned int permission);
void file_close(int file_descriptor);

#endif