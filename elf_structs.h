#ifndef ELF_STRUCTS_H
#define ELF_STRUCTS_H

#include<elf.h>

typedef struct ElfProg
{
	Elf32_Ehdr header;		  //elf header
	Elf32_Phdr *phdr_tab;	  //program header table
	Elf32_Section *sections;   //program sections
	Elf32_Shdr *shdr_tab;	  //section header table

} ElfProg;

#endif