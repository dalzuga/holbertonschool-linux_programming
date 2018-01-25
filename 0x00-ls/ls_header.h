#ifndef _LS_HEADER_H_
#define _LS_HEADER_H_

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * struct ls_struct - stores needed information for the program
 *
 * @dir: the address of the DIR struct
 * @read: the pointer to read the stream returned by readdir
 * @dir_path_name: array of directory paths
 * @tmp: convenience variable to store temporary information
 *
 * Description: This struct is being used to store necessary variables as it
 * gets passed around from function to function.
 */
typedef struct ls_struct
{
	DIR *dir;
	struct dirent *read;
	const char **dir_path_name;
	int tmp;
} ls_struct;

typedef struct ll_node
{
	char *str;
	int n;
} ll_node;

typedef struct ll
{
	struct ll *prev;
	struct ll *next;
	struct ll_node *data;
} ll;

/* alloc_init_lss - allocates and zeroes the ls_struct */
int alloc_init_lss(ls_struct **lss);

/* _opendir - wrapper for opendir with checks. */
int _opendir(ls_struct *lss);

/* ls_loop - loop through directory entries */
void ls_loop(ls_struct *lss);

#endif
