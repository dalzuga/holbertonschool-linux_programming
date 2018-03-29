#include "hnm_header.h"

/**
 * symbol_table64 - gets the symbol table of a 64-bit ELF file
 *
 * @f: pointer to file stream
 *
 * Return: 1 on success, 0 on error.
 */
int symbol_table64(FILE *f)
{
	ELF64_Ehdr *elf_header;
	int tmp = 0, tmp1 = 0;

	tmp = fseek(f, 0, SEEK_SET);
	if (tmp == -1)
	{
		perror("fseek");
		exit(EXIT_FAILURE);
	}

	tmp1 = fread(elf_header->e_ident[EI_DATA], 1, 1, f);

	printf("tmp1: %d\n", tmp1);

	return (1);
}
