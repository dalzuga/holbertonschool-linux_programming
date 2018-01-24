#include "ls_header.h"

/**
 * ls_loop - loop through directory entries
 *
 * @ds: the address of the main dir_struct
 */
void ls_loop(dir_struct *ds)
{
	ds->read = readdir(ds->dir);
	while (1)
	{
		if (ds->read == NULL)
			break;

		printf("%s (%d) ", (ds->read)->d_name, (ds->read)->d_type);
		ds->read = readdir(ds->dir);
	}
	printf("\n");
}
