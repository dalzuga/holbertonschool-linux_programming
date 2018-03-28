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
	int tmp = 0, tmp2 = 0;

	tmp = fseek(f, 4, SEEK_SET);
	if (tmp == -1)
	{
		perror("fseek");
		exit(EXIT_FAILURE);
	}
	tmp2 = fread(&byte, 1, 1, f);
	if (tmp2 < 1)
	{
		perror("fread");
		exit(EXIT_FAILURE);
	}
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
	int tmp = 0, tmp2 = 0, tmp3 = 0;
	const char elf_bytes[6] = { 0x7f, 0x45, 0x4c, 0x46, 0x02, '\0' };
	char *read_bytes = NULL;

	tmp = fseek(f, 0, SEEK_SET);
	if (tmp == -1)
	{
		perror("fseek");
		exit(EXIT_FAILURE);
	}

	tmp2 = fread(&read_bytes, 5, 1, f);
	printf("tmp2: %d\n", tmp2);
	if (tmp2 < 1)
	{
		perror("fread");
		exit(EXIT_FAILURE);
	}

	printf("elf_bytes: %s\n", elf_bytes);

	tmp3 = strncmp(elf_bytes, read_bytes, 5);
	printf("tmp3 [boolean] is: %d\n", tmp3);

	return(1);
}
