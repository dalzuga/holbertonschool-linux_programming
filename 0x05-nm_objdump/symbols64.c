#include "hnm_header.h"

/**
 * p_symbol_table - prints the symbol table of an ELF file
 *
 * @f: pointer to file stream
 *
 * Return: 1 on success, 0 on error.
 */
int p_symbol_table(FILE *f)
{
	Elf64_Ehdr *e_header;
	Elf64_Sym *symtab;
	Elf64_Shdr *shdr;
	int tmp = 0, tmp1 = 0;

	e_header = malloc(sizeof(Elf64_Ehdr));
	if (e_header == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	shdr = malloc(sizeof(Elf64_Shdr));
	if (shdr == NULL)
		exit(EXIT_FAILURE);

	shdr = fread(e_header->e_shoff, e_shnum, 1, f); /* read section hdr */
	if (fread != 1)
		exit(EXIT_FAILURE);

	if (e_header->e_shoff == 0) /* nothing to print */
		return (1);	      /* success */

	if (0)
		printf("%p", (void *) symtab);

	return (1);
}
