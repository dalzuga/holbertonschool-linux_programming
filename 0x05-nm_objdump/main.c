#include "hnm_header.h"

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

	if (argc <= 1)
		filename = strdup("a.out");
	else
		filename = strdup(argv[1]);

	if (filename == NULL)
		return (EXIT_FAILURE);

	hnm_func(filename);

	free(filename);
	return (EXIT_SUCCESS);
}

/**
 * hnm_func - opens an ELF file
 *
 * @filename: the name of the file.
 */
void hnm_func(char *filename)
{
	if ( access(filename, F_OK) != -1 )
	{
		printf("File exists.\n");
	}
	else
	{
		fprintf(stderr, "hnm: '%s': No such file\n", filename);
	}
}
