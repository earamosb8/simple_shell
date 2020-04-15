#include "shell.h"
/**
 * fun_per - free line
 * @line: string to free
 * Return: (EXIT_FAILURE)
 */
int fun_per(char *line)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(line);
	exit(EXIT_SUCCESS);
}
/**
 * print_error - print message error
 * @argv: name of the program
 * @counter: how many functions maked
 * @token: array of strings
 */
void print_error(char **argv, unsigned int counter, char *token)
{
	_printf("%s: %i: %s: not found\n", argv[0], counter, token);
}
