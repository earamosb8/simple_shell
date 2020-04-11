#include "shell.h"
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
/**
 * free_all - free all double pointers
 * @token: the pointer to free
 * Return: void
 */
void free_all(char **token)
{
	unsigned int i = 0;

	if (token != NULL)
	{
		while (token[i])
		{
			free(token[i]);
			i++;
		}
		free(token);
	}
}
/**
 * send_free - Function to send free when the child is not created
 * @line: buffer created by getline
 * @token: array of commands
 * Return: void
 */
void send_free(char *line, char **token)
{
	free(line);
	free_all(token);
}
