#ifndef _LS_HEADER_H_
#define _LS_HEADER_H_

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

typedef struct dir_struct
{
	DIR *dir;
	struct dirent *read;
	const char* dir_path_name;
	int tmp;
} dir_struct;

typedef struct fp_struct
{
	void (*fp)(void);
} fp_struct;

/* alloc_init_ds - allocates and zeroes the dir_struct */
int alloc_init_ds(dir_struct **ds);

/* _opendir - wrapper for opendir with checks. */
int _opendir(dir_struct *ds);

#endif
