#include "shell.h"
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

	/** Token NULL */
	if (token == NULL)
		free(line), exit(EXIT_FAILURE);
	/** if command is "exit" */
	else if ((_strcmp(token[0], "exit") == 0))
		free(line), free_all(token), exit(EXIT_SUCCESS);
	/** if command is "env" */
	else if (_strcmp("env", token[0]) == 0)
	{
		while (env[i])
		{
			_printf("%s\n", env[i]);
			i++;
		}
		free(line);
		free_all(token);
		exit(EXIT_SUCCESS);
	}
	/** if the command have the full path */
	else if (stat(token[0], &buffer) == 0)
		execve(token[0], token, env);
	/** if dont find full path, looking for that or print error*/
	else
	{
		print_error(argv, counter, token, line);
		free(line);
		free_all(token);
	/**	search_path(token, line, argv, env, counter);*/
	}
}