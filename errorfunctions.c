#include "shell.h"

void print_error (char **argv, unsigned int counter , char *token)
{
	_printf("%s: %i: %s: not found \n" , argv[0], counter, token);
}
