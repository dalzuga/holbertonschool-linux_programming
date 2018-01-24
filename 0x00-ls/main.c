#include "ls_header.h"

/**
 * main - entry point for ls.
 *
 * @argc: stores the number of arguments
 * @argv: the array of arguments
 *
 * Return: 1 on failure, 0 on success.
 */
int main(int argc, char *argv[])
{
	dir_struct *ds = NULL;

	if (alloc_init_ds(&ds) == 1)
		return (1);

	if (argc >= 2)
		ds->dir_path_name = argv[1];

	if (_opendir(ds) == 1)
		return (1);

	ls_loop(ds);

	ds->tmp = closedir(ds->dir);
	if (ds->tmp == -1)
	{
		perror("closedir");
		return (1);
	}

	free(ds);

	return (0);
}

/**
 * alloc_init_ds - allocates and zeroes the dir_struct
 *
 * @ds: the address of the pointer to the dir_struct
 *
 * Return: 1 on failure, 0 on success.
 */
int alloc_init_ds(dir_struct **ds)
{
	*ds = malloc(sizeof(dir_struct));
	if (*ds == NULL)
	{
		perror("malloc");
		return (1);
	}

	(*ds)->dir = NULL;
	(*ds)->read = NULL;
	(*ds)->tmp = 0;
	(*ds)->dir_path_name = ".";

	printf("address of (*ds)->dir: %p\n", (void *) (*ds)->dir);

	return (0);
}

/**
 * _opendir - wrapper for opendir with checks.
 *
 * @ds: the address of the main dir_struct
 *
 * Return: 1 on failure, 0 on success.
 */
int _opendir(dir_struct *ds)
{
	printf("address of ds: %p\n", (void *) ds);
	ds->dir = opendir(ds->dir_path_name);
	if (ds->dir == NULL)
	{
		perror("ls");
		return (1);
	}

	return (0);
}
