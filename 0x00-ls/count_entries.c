#include "ls_header.h"

/**
 * count_entries - counts the number of entries in a recently opened directory
 *
 * @lss: the main ls struct
 *
 * Return: the number of entries in the directory.
 */
int count_entries(ls_struct *lss)
{
	int i = 0;

	if (_opendir(lss) == 1)
	{
		perror("_opendir");
		exit(EXIT_FAILURE);
	}

	/* at this point, we have opened the DIR struct */

	while (1)
	{
		lss->read = readdir(lss->dir);
		if (lss->read == NULL)
			break;
		i++;
	}

	closedir(lss->dir);
	return (i);
}
