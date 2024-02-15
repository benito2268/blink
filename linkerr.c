#include<stdio.h>
#include<stdlib.h>
#include"linkerr.h"

//this commit added as a test :)

void link_err(int err_code, const char *msg_arg) 
{
	switch(err_code)
	{
	default:
		printf("%s%d %s%s\n", "blink: a fatal linker error occurred. Code: ", err_code, "Arg: ", msg_arg);
		break;
	}

	exit(type);
} 
