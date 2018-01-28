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

/* alloc_init_lss - allocates and zeroes the ls_struct */
int alloc_init_lss(ls_struct **lss);

/* _opendir - wrapper for opendir with checks. */
int _opendir(ls_struct *lss);

/* ls_loop - loop through directory entries */
void ls_loop(ls_struct *lss);

/* count_entries - counts the number of entries in an opened directory */
int count_entries(ls_struct *lss);

/* _strlen - gets the length of a string. */
int _strlen(const char *s);

/* _strdup - duplicates a string */
char *_strdup(const char *s1);

/* _strcmp - compare two strings */
int _strcmp(const char *s1, const char *s2);

#endif
