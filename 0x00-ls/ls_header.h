#ifndef LS_HEADER_H
#define LS_HEADER_H

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

typedef struct dir_struct
{
	DIR *dir;
	struct dirent *read;
	int tmp;
} dir_struct;

/* alloc_init_ds - allocates and zeroes the dir_struct */
int alloc_init_ds(dir_struct **ds);

/* _opendir - wrapper for opendir with checks. */
int _opendir(dir_struct *ds, const char *dir_name);

#endif
