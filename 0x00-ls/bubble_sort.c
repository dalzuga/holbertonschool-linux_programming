#include "ls_header.h"

/**
 * ls_loop_lvl2 - loop nested inside ls_loop
 *
 * @lss: the address of the main ls_struct
 * @n: the number of entries
 * @entry: the array of entries (needs to be freed by ls_loop)
 */
void ls_loop_lvl2(ls_struct *lss, int n, char **entry)
{
	int i = 0;

	/* at this point, we have opened the DIR struct */

	lss->read = readdir(lss->dir);
	while (i < n)
	{
		if (lss->read == NULL)
		{
			perror("directory total entries change detected");
			exit(EXIT_FAILURE);
		}

		entry[i] = _strdup(lss->read->d_name);
		lss->read = readdir(lss->dir);
		i++;
	}

	bubble_sort(n, entry);

	/* print the entries */
	for (i = 0; i < n; i++)
	{
		if (entry[i][0] == '.')
		{
		}
		else if (i != (n - 1))
		{
			printf("%s ", entry[i]);
		}
		else
		{
			printf("%s", entry[i]);
		}
	}
	printf("\n");
}
