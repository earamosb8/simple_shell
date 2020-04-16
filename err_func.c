#include "shell.h"
/**
 * read_error - free line
 * @line: string to free
 * Return: (EXIT_FAILURE)
 */
int read_error(char *line)
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
 * @line: string with the command from the user
 */
void print_error(char **argv, unsigned int counter, char **token, char *line)
{
	char mensaje[30];

	sprintf(mensaje, "%s: %d: %s: not found\n", argv[0], counter, token[0]);
	write(STDERR_FILENO, mensaje, _strlen(mensaje));
	free(line);
	free_all(token);
	exit(127);
}
