#include "ls_header.h"

/**
 * ls_loop - loop through directory entries
 *
 * @lss: the address of the main ls_struct
 */
void ls_loop(ls_struct *lss)
{
	char **entry = NULL;
	char *entry_tmp = NULL;
	int n = 0;
	int i = 0;
	int j = 0;

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
		lss->read = readdir(lss->dir);
		i++;
	}

	/* bubble sort the entries */
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (_strcmp(entry[j], entry[i]) > 0)
			{
				entry_tmp = entry[j];
				entry[j] = entry[i];
				entry[i] = entry_tmp;
			}
		}
	}

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

	/* free the entries */
	i = 0;
	while (i < n)
	{
		free(entry[i]);
		i++;
	}

	free(entry);
}
