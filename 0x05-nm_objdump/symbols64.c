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
	Elf64_Ehdr *elf_header;
	int tmp = 0, tmp1 = 0;

	elf_header = malloc(sizeof(Elf64_Ehdr));
	if (elf_header == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	tmp = fseek(f, EI_DATA, SEEK_SET);
	if (tmp == -1)
	{
		perror("fseek");
		exit(EXIT_FAILURE);
	}
	tmp1 = fread(elf_header->e_ident + EI_DATA, 1, 1, f);

	printf("EI_DATA [hex]: %x\n", elf_header->e_ident[EI_DATA]);

	if (tmp1 == ELFDATA2LSB)
		printf("little endian\n");
	else if (tmp1 == ELFDATA2MSB)
		printf("big endian\n");
	else
	{
		perror("");
	}

	tmp1 = fread(elf_header->e_ident + EI_DATA, 1, 1, f);

	return (1);
}
