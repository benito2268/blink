#ifndef LOAD_FILE_H
#define LOAD_FILE_H

#include<stdbool.h>
#include<elf.h>

bool is_elf32(Elf32_Ehdr header);
ElfProg *load_file(const char *filename);

#endif