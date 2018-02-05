#include "ls_header.h"

/**
 * bubble_sort - bubble sort the entries
 *
 * @n: the number of entries
 * @entry: the array of entries (needs to be freed by ls_loop)
 */
void bubble_sort(int n, char **entry)
{
	char *entry_tmp = NULL;
	int i = 0;
	int j = 0;

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
}
