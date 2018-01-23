#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

typedef struct dir_struct
{
	DIR *dir;
	struct dirent *read;
	int tmp;
} dir_struct;

int alloc_init_ds(dir_struct **ds);
int _opendir(dir_struct *ds, const char *dir_name);
