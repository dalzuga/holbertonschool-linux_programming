#include "ls_header.h"

/**
 * ls_loop - loop through directory entries
 *
 * @lss: the address of the main ls_struct
 */
void ls_loop(ls_struct *lss)
{
	/* char **entry = NULL; */
	int n = 0;

	n = count_entries(lss);

	printf("total: %d\n", n);

	if (_opendir(lss) == 1)
	{
		perror("_opendir");
		exit(EXIT_FAILURE);
	}

	/* at this point, we have opened the DIR struct */

	lss->read = readdir(lss->dir);
	while (1)
	{
		if (lss->read == NULL)
			break;

		printf("%s (%d) ", (lss->read)->d_name, (lss->read)->d_type);
		lss->read = readdir(lss->dir);
	}
	printf("\n");
}
