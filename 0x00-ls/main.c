#include "ls_header.h"

/**
 * main - entry point for the program.
 *
 * @argc: stores the number of arguments
 * @argv: the array of arguments
 *
 * Return: 1 on failure, 0 on success.
 */
int main(int argc, char *argv[])
{
	ls_struct *lss = NULL;

	if (alloc_init_lss(&lss) == 1)
		return (1);

	if (argc >= 2)
	{
		lss->dir_path_name = argv[1];
	}

	if (_opendir(lss) == 1)
		return (1);

	ls_loop(lss);

	lss->tmp = closedir(lss->dir);
	if (lss->tmp == -1)
	{
		perror("closedir");
		return (1);
	}

	free(lss);

	return (0);
}

/**
 * alloc_init_lss - allocates and zeroes the ls_struct
 *
 * @lss: the address of the pointer to the ls_struct
 *
 * Return: 1 on failure, 0 on success.
 */
int alloc_init_lss(ls_struct **lss)
{
	*lss = malloc(sizeof(ls_struct));
	if (*lss == NULL)
	{
		perror("malloc");
		return (1);
	}

	(*lss)->dir = NULL;
	(*lss)->read = NULL;
	(*lss)->tmp = 0;
	(*lss)->dir_path_name = ".";

	printf("address of (*lss)->dir: %p\n", (void *) (*lss)->dir);

	return (0);
}

/**
 * _opendir - wrapper for opendir with checks.
 *
 * @lss: the address of the main ls_struct
 *
 * Return: 1 on failure, 0 on success.
 */
int _opendir(ls_struct *lss)
{
	printf("address of lss: %p\n", (void *) lss);
	lss->dir = opendir(lss->dir_path_name);
	if (lss->dir == NULL)
	{
		perror("opendir");
		return (1);
	}

	return (0);
}
