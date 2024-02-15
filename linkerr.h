// defines the link_err() function to print an error message and exit
// author: Ben Staehle
// date:   12/18/23

#ifndef LINKERR_H
#define LINKERR_H

#define ERR_NO_SUCH_FILE 1
#define ERR_SYM_NODEF 2
#define ERR_SYM_MULTDEF 3
#define ERR_FILE_NOT_ELF 4
#define ERR_INVALID_ARCH 5
#define ERR_FILE_NOT_RELOCATABLE 6
#define ERR_INTERN 7

void link_err(int err_code, const char *msg_arg);

#endif