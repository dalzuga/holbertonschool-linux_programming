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

	tmp = fseek(f, 0, SEEK_SET);
	if (tmp == -1)
		exit(EXIT_FAILURE);

	/* read into e_header */
	tmp1 = fread(e_header, sizeof(Elf64_Ehdr), 1, f);
	if (tmp1 != 1)
		exit(EXIT_FAILURE);

	/* printf("e_header->e_shoff: %lu\n", e_header->e_shoff); */

	if (e_header->e_shoff == 0) /* nothing to print */
		return (1);	      /* success */

	tmp = fseek(f, e_header->e_shoff, SEEK_SET);
	if (tmp == -1)
		exit(EXIT_FAILURE);

	shdr = malloc(sizeof(Elf64_Shdr));
	if (shdr == NULL)
		exit(EXIT_FAILURE);

	/* read into section hdr */
	tmp1 = fread(shdr, sizeof(Elf64_Shdr), 1, f);
	if (tmp1 != 1)
		exit(EXIT_FAILURE);

	printf("shdr->sh_name: %s\n", e_header->e_shoff + shdr->sh_name);

	if (0)
		printf("%p", (void *) symtab);

	return (1);
}
