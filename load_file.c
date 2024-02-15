#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"linkerr.h"
#include"elf_structs.h"
#include"load_file.h"

bool is_elf32(Elf32_Ehdr header)
{
	//check that the first 4 bytes are ".ELF"
	if(header.e_ident[EI_MAG0] == 0x7F
		&& (char)header.e_ident[EI_MAG1] == 'E'
		&& (char)header.e_ident[EI_MAG2] == 'L'
		&& (char)header.e_ident[EI_MAG3] == 'F')
	{
		if(header.e_type == ET_REL)
		{
			return true;
		}
	}

	//TODO check other ELF header fields

	return false;
}

ElfProg *load_file(const char *filename)
{
	FILE *in;
	ElfProg *ret = malloc(sizeof(Elf32_Ehdr));

	in = fopen(filename, "rb");
	if(in == NULL)
	{
		link_err(ERR_NO_SUCH_FILE, ERR_NO_MESSAGE);
	}

	//read the elf header
	Elf32_Ehdr temp;
	fread(&temp, sizeof(Elf32_Ehdr), 1, in);

	//check if actually ELF format
	if(!is_elf32(temp))
	{
		link_err(ERR_FILE_NOT_ELF, filename);
	}

	ret->header = temp;

	fclose(in);
	return ret;
}