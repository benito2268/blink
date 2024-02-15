#include<stdio.h>
#include<stdlib.h>

#ifndef __linux__
    #error "must be compiled on linux"
#endif

#include"elf_structs.h"
#include"load_file.h"

void fill_header(Elf32_Ehdr *hdr)
{
    //e_ident
    hdr->e_ident[EI_MAG0] = 0x7F;
    hdr->e_ident[EI_MAG1] = 0x45;     //'E'
    hdr->e_ident[EI_MAG2] = 0x4C;     //'L'
    hdr->e_ident[EI_MAG3] = 0x46;     //'F'

    hdr->e_ident[EI_CLASS] = 0x1;     //32 bits
    hdr->e_ident[EI_DATA]  = 0x1;     //little-endian - 2's compliment
    hdr->e_ident[EI_VERSION] = 0x1;   //current version
    hdr->e_ident[EI_OSABI] = 0x00;    //UNIX - System V

    //other OS info
    hdr->e_type = ET_EXEC;
    hdr->e_machine = EM_386;
    hdr->e_version = EV_CURRENT;

    //TODO actually make work
    hdr->e_entry = 0x0;
    hdr->e_phoff = 0x0;
    hdr->e_shoff = 0x0;
    hdr->e_flags = 0x0;
    hdr->e_ehsize = 0x34;
    hdr->e_phentsize = 0x0;
    hdr->e_phnum = 0x0;
    hdr->e_shentsize = 0x0;
    hdr->e_shnum = 0x0;
    hdr->e_shstrndx = 0x0;
}

// void struct2elf(Elf32_Ehdr header, const char *exefile)
// {
//     FILE *out = fopen(exefile, "wb");
//     if(out == NULL)
//     {
//         link_err(ERR_INTERN, exefile);
//     }

//     //write the elf header to the file
//     fwrite((void*)(&header), sizeof(Elf32_Ehdr), 1, out);
//     fclose(out);
// }

int main(int argc, char *argv[])
{
    //Elf32_Ehdr header;
    //fill_header(&header);

   // struct2elf(header, "../out/an_exec_file");

    ElfProg *p = load_file("an_exec_file");

    return 0;
}
