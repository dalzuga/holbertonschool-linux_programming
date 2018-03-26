#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - entry point for hnm.
 *
 * @argc: number of parameters passed to the program
 * @argv: the parameter vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 * 
 */
int main(int argc, char **argv __attribute__((unused)))
{
	char *filename = NULL;
	if (argc <= 2)
	{
		filename = strdup("a.out");
		if (filename == NULL)
			return (EXIT_FAILURE);
	}

	free(filename);
	return (EXIT_SUCCESS);
}
