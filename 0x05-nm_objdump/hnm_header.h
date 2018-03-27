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

#endif
