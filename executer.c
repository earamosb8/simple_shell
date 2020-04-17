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
		search_path(token, line, argv, env, counter);
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
void search_path(char **token, char *line, char **argv, char **env, int c)
{
	struct stat fileStat;
	int i = 0, len_com = 0, len_p = 0;
	char *full_path;
	char **path_com;
	const char *delim_path = ":";
	const char delim_lot = ':';

	len_com = _strlen(token[0]);
	full_path = getenv("PATH");

	_strcat(full_path, "0");

	path_com = tokenize(full_path, delim_path, delim_lot);
	while (path_com[i])
	{
		len_p = _strlen(path_com[i]);
		path_com[i] = _realloc(path_com[i], sizeof(char *) * len_p,
			sizeof(char *) * (len_p + len_com + 2));
		_strcat(path_com[i], "/");
		_strcat(path_com[i], token[0]);

		if (stat(path_com[i], &fileStat) == 0)
			execve(path_com[i], token, env);
		i++;
	}
	print_error(argv, c, token, line);
	free_all(path_com);
	free(full_path);
	exit(EXIT_FAILURE);
}
