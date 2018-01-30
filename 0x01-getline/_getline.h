#ifndef __GET_LINE_H_
#define

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define READ_SIZE 64

char *_getline(const int fd);

#endif
