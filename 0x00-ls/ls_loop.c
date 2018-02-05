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

	entry = malloc(sizeof(char *) * n);
	if (entry == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	ls_loop_lvl2(lss, n, entry);

	/* free the entries */
	i = 0;
	while (i < n)
	{
		free(entry[i]);
		i++;
	}

	free(entry);
}
