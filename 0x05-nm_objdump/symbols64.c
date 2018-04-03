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
	Elf64_Ehdr *e_hdr = NULL;
	Elf64_Sym *symtab = NULL;
	Elf64_Shdr *s_hdr = NULL;
	char *s_name = NULL;
	int tmp = 0, tmp1 = 0, i = 0;

	e_hdr = malloc(sizeof(Elf64_Ehdr));
	if (e_hdr == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	tmp = fseek(f, 0, SEEK_SET);
	if (tmp == -1)
		exit(EXIT_FAILURE);

	/* read into e_hdr */
	tmp1 = fread(e_hdr, sizeof(Elf64_Ehdr), 1, f);
	if (tmp1 != 1)
		exit(EXIT_FAILURE);

	printf("e_hdr->e_shoff: %lu\n", e_hdr->e_shoff);
	printf("e_hdr->e_shnum: %d\n", e_hdr->e_shnum);
	printf("e_hdr->e_shentsize: %d\n", e_hdr->e_shentsize);

	if (e_hdr->e_shoff == 0) /* nothing to print */
		return (1);	      /* success */

	/*
         * not necessary
         * /\* seek into start of section header *\/
	 * tmp = fseek(f, e_hdr->e_shoff, SEEK_SET);
	 * if (tmp == -1)
	 * 	exit(EXIT_FAILURE);
         */

	s_hdr = malloc(sizeof(Elf64_Shdr));
	if (s_hdr == NULL)
		exit(EXIT_FAILURE);

	printf("e_shstrndx: %d\n", e_hdr->e_shstrndx);
	printf("e_shstrndx SHN_UNDEF: %d\n", SHN_UNDEF);

	for (i = 0; i < e_hdr->e_shnum; i++)
	{
		/* read section hdr */
		tmp1 = fread(s_hdr, e_hdr->e_shentsize, 1, f);
		if (tmp1 != 1)
			exit(EXIT_FAILURE);

		printf("s_hdr->sh_name: %ull\n", s_hdr->sh_name);
		if (i == e_hdr->e_shstrndx)
		{
			printf("%d\n", e_hdr->e_shstrndx);
			printf("%s\n", (char *) s_hdr + (s_hdr->sh_name));
			printf("%d\n", s_hdr->sh_type);
			printf("%d\n", SHT_NULL);
		}

		/*
                 * not the right way
                 * /\* seek into name of a section *\/
		 * tmp = fseek(f, s_hdr->sh_name, SEEK_SET);
		 * if (tmp == -1)
		 * 	exit(EXIT_FAILURE);
                 */

		/* printf("sh_name: %ull\n", s_hdr->sh_type); */
	}

	printf("MACRO: %ull\n", SHT_STRTAB);

	if (0)			/* avoid compiler unused warning */
	{
		printf("%p", (void *) symtab);
		printf("s_name: %s\n", s_name);
	}

	return (1);
}
