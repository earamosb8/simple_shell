#include "shell.h"
/**
 * free_all - free all double pointers
 * @tok: the pointer to free
 * Return: void
 */
void free_all(char **tok)
{
	unsigned int i = 0;

	if (tok == NULL)
		return;
	if (tok)
	{
		while (tok[i])
		{
			free(tok[i]);
			i++;
		}
		if (tok[i] == NULL)
			free(tok[i]);
	}
	free(tok);
}
/**
 * send_free - Function to send free when the child is not created
 * @line: buffer created by getline
 * @token: array of commands
 * Return: void
 */
void send_free(char *line, char **token)
{
	if (line == NULL)
		;
	else
		free(line);
	free_all(token);
}
