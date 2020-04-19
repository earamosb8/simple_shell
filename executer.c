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
void ejecutador(char **token, char *line, char **argv, char **env, int counter, char **command)
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
		search_path(token, line, argv, env, counter, command);
}
/**
 * search_path - look for the complete path
 * @token: commands tokenized
 * @line: complete string from stdinput
 * @argv: arguments of program
 * @env: enviroment variables
 * @line: string enetered by stdinput
 * @c: counter
 */
void search_path(char **token, char *line, char **argv, char **env, int c , char **command)
{
	struct stat fileStat;
	int i = 0, len_com = 0, len_p = 0;
	char *full_path;
	const char *delim_path = ":";
	const char delim_lot = ':';
	char *nuevo = NULL;

	len_com = _strlen(token[0]);
	full_path = getenv("PATH");

	_strcat(full_path, "0");

	command = tokenize(full_path, delim_path, delim_lot);

	while (command[i])
	{
		len_p = _strlen(command[i]);
		nuevo = malloc(len_p + len_com + 2);
		strcpy(nuevo, command[i]);
		_strcat(nuevo, "/");
		_strcat(nuevo, token[0]);

		if (stat(nuevo, &fileStat) == 0)
			execve(nuevo, token, env);

		free(nuevo);
		i++;
	}

	free_all(command);
	print_error(argv, c, token, line);

	exit(EXIT_FAILURE);

}
