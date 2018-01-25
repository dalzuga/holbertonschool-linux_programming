#include "ls_header.h"

/**
 * ls_loop - loop through directory entries
 *
 * @lss: the address of the main ls_struct
 */
void ls_loop(ls_struct *lss)
{
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
