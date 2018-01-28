#include "ls_header.h"

/**
 * ls_loop - loop through directory entries
 *
 * @lss: the address of the main ls_struct
 */
void ls_loop(ls_struct *lss)
{
	char **entry = NULL;
	int n = 0;
	int i = 0;

	n = count_entries(lss);

	if (_opendir(lss) == 1)
	{
		perror("_opendir");
		exit(EXIT_FAILURE);
	}

	/* at this point, we have opened the DIR struct */

	entry = malloc(sizeof(char *) * n);
	if (entry == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	lss->read = readdir(lss->dir);
	while (i < n)
	{
		if (lss->read == NULL)
		{
			perror("directory total entries change detected");
			exit(EXIT_FAILURE);
		}

		entry[i] = _strdup(lss->read->d_name);
		printf("%s ", entry[i]);
		lss->read = readdir(lss->dir);
		i++;
	}
	printf("\n");

	i = 0;
	while (i < n)
	{
		free(entry[i]);
		i++;
	}

	free(entry);
}
