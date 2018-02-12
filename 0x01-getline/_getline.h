#ifndef __GET_LINE_H_
#define __GET_LINE_H_

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ_SIZE 64

char *_getline(const int fd);

char *getfirstline(const int fd, int *seek_point);

int strnchkc(const char *s, int n, char c);

int strgetci(char *s, char c);

#endif
