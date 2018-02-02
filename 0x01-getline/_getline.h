#ifndef __GET_LINE_H_
#define __GET_LINE_H_

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ_SIZE 64

char *_getline(const int fd);

char *_getfirstline(const int fd);

#endif
