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
 * @tok: the pointer to free
 * Return: void
 */
void free_all(char **tok)
{
	unsigned int i = 0;

	if (tok != NULL)
	{
		while (tok[i])
		{
			free(tok[i]);
			i++;
		}
		free(tok);
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
/**
 * ejecutador - execute
 * @token: array of commands
 * @line: buffer created by getline
 * @argv: array argv
 * @env: array env
 * @counter: counter
 * Return: void
 */
void ejecutador(char **token, char *line, char **argv, char **env, int counter)
{

	struct stat buffer;
	int i = 0;

	if (token == NULL)
		free(line), exit(EXIT_SUCCESS);
	else if (_strcmp("env", token[0]) == 0)
	{
		while (env[i])
		{
			_printf("%s\n", env[i]);
			i++;
		}
		exit(EXIT_SUCCESS);
	}
	else if (stat(token[0], &buffer) == -1 || token[1])
	{
		_printf("%s: No such file or directory\n", argv[0]);
	}
	else if (execve(token[0], token, env) == -1)
	{
		print_error(argv, counter, token[0]);
		exit(EXIT_FAILURE);
	}
}
