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

	if (argc <= 2)
		filename = strdup("a.out");
	else
		filename = strdup(argv[0]);

	if (filename == NULL)
		return (EXIT_FAILURE);

	hnm_func(filename);

	free(filename);
	return (EXIT_SUCCESS);
}

/**
 * hnm_func - opens an ELF file and prints its contents
 *
 * @filename: the name of the file.
 */
void hnm_func(char *filename)
{
	printf("filename: %s\n", filename);
}
