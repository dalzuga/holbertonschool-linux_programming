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
	Elf64_Ehdr *e_header = NULL;
	Elf64_Sym *symtab = NULL;
	Elf64_Shdr *s_hdr = NULL;
	char *s_name = NULL;
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

	printf("e_header->e_shoff: %lu\n", e_header->e_shoff);
	printf("e_header->e_shnum: %d\n", e_header->e_shnum);
	printf("e_header->e_shentsize: %d\n", e_header->e_shentsize);

	if (e_header->e_shoff == 0) /* nothing to print */
		return (1);	      /* success */

	/*
         * not necessary
         * /\* seek into start of section header *\/
	 * tmp = fseek(f, e_header->e_shoff, SEEK_SET);
	 * if (tmp == -1)
	 * 	exit(EXIT_FAILURE);
         */

	s_hdr = malloc(sizeof(Elf64_Shdr));
	if (s_hdr == NULL)
		exit(EXIT_FAILURE);

	/* read into section hdr */
	tmp1 = fread(s_hdr, sizeof(Elf64_Shdr), 1, f);
	if (tmp1 != 1)
		exit(EXIT_FAILURE);

	/* seek into name of a section */
	tmp = fseek(f, s_hdr->sh_name, SEEK_SET);
	if (tmp == -1)
		exit(EXIT_FAILURE);
	s_name = malloc(sizeof(char) * 20);
	fread(s_name, sizeof(char) * 20, 1, f);

	printf("s_name: %s\n", s_name);

	if (0)
		printf("%p", (void *) symtab);

	return (1);
}
