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
	Elf64_Sym *symtab;
	Elf64_Shdr *shdr;
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
	if (fread != 1)
		exit(EXIT_FAILURE);

	printf("EI_DATA [hex]: %x\n", elf_header->e_ident[EI_DATA]);

	if (tmp1 == ELFDATA2LSB)
		printf("little endian\n");
	else if (tmp1 == ELFDATA2MSB)
		printf("big endian\n");
	else
		return (0);

	shdr = malloc(sizeof(Elf64_Shdr));
	if (shdr == NULL)
		exit(EXIT_FAILURE);

	shdr = fread(elf_header->e_shoff, Elf64_Off, 1, f);
	if (fread != 1)
		exit(EXIT_FAILURE);

	symtab = malloc(sizeof(Elf64_Sym));
	if (symtab == NULL)
		exit(EXIT_FAILURE);

	symtab = fread();

	if (0)
		printf("%p", (void *) symtab);

	return (1);
}
