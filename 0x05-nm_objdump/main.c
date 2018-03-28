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
	FILE *f;

	if (access(filename, F_OK) != -1)
	{
		printf("File exists.\n");
		f = fopen(filename, "r");
		if (hnm_verify_elf(f) == 1)
			printf("This is an ELF file. (fake msg)\n");
		else
			fprintf(stderr, "hnm: %s: File format not recognized\n"
				, filename);
	}
	else
	{
		fprintf(stderr, "hnm: '%s': No such file\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * hnm_verify_elf - checks the ELF magic number of a file stream
 *
 * @f: pointer to file stream
 *
 * Return: 1 if file is ELF, 0 otherwise.
 */
int hnm_verify_elf(FILE *f __attribute__((unused)))
{
	char byte;
	int tmp = 0;

	fseek(f, 4, SEEK_SET);
	tmp = fread(&byte, 1, 1, f);
	if (tmp == 0)
		exit(EXIT_FAILURE);
	printf("the byte is: 0x%x\n", (unsigned int) byte);

	if (byte == 2)
		return (hnm_verify_elf64(f));

	return (0);
}

/**
 * hnm_verify_elf64 - verifies this is a 64-bit ELF file
 *
 * @f: pointer to file stream
 *
 * Return: 1 if file is ELF, 0 otherwise.
 */
int hnm_verify_elf64(FILE *f __attribute__((unused)))
{
	return(1);
}
