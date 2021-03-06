#ifndef _HNM_HEADER_H
#define _HNM_HEADER_H

#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* hnm_func - opens an ELF file and prints its contents */
void hnm_func(char *filename);

/* hnm_verify_elf - checks the ELF magic number of a file stream */
int hnm_verify_elf(FILE *f);

/* hnm_verify_elf64 - verifies this is a 64-bit ELF file */
int hnm_verify_elf64(FILE *f);

/** hnm_verify_elf32 - verifies this is a 32-bit ELF file */
int hnm_verify_elf32(FILE *f);

/* p_symbol_table - prints the symbol table of a 64-bit ELF file */
int p_symbol_table(FILE *f);

#endif
