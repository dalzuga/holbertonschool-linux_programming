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

	while (1)
	{
		lss->read = readdir(lss->dir);
		if (lss->read == NULL)
			return (i);
		i++;
	}
}
