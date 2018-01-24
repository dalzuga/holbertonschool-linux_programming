#ifndef _LS_HEADER_H_
#define _LS_HEADER_H_

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * struct dir_struct - stores needed information for the program
 *
 * @dir: the address of the DIR struct
 * @read: the pointer to read the stream returned by readdir
 * @dir_path_name: the directory path
 * @tmp: convenience variable to store temporary information
 *
 * Description: This struct is being used to store necessary variables as it
 * gets passed around from function to function.
 */
typedef struct dir_struct
{
	DIR *dir;
	struct dirent *read;
	const char *dir_path_name;
	int tmp;
} dir_struct;

/* alloc_init_ds - allocates and zeroes the dir_struct */
int alloc_init_ds(dir_struct **ds);

/* _opendir - wrapper for opendir with checks. */
int _opendir(dir_struct *ds);

/* ls_loop - loop through directory entries */
void ls_loop(dir_struct *ds);

#endif
