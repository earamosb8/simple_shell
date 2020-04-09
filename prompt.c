#include "shell.h"
/**
 * main - fork & wait example
 * @argc: void arg
 * @argv: arguments passed by stdinput
 * @env: eviroment
 * Return: Always 0.
 */
int main(int argc, char *env[])
{
	char *line = NULL, *token, *argv[32];
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status, i = 0;
	(void) argc;

	print_sign();

	while ((read = getline(&line, &len, stdin)))
	{
		if (read < 0)
		{
			perror("Unable to allocate buffer");
			return (EXIT_FAILURE);
		}

//		token = tokenize(line);

		token = strtok(line, " \t\n\r");
		while (token != NULL)
		{
			argv[i] = token;
			if (_strcmp(argv[0], "exit") == 0)
			{
				exit(EXIT_SUCCESS);
			}
			token = strtok(NULL, " \t\n\r");
			i++;
		}
		argv[i] = NULL;
		i = 0;
	/*	if (_strcmp(argv[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		} */
		child_pid = fork();
		if ((child_pid) == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				perror("Error: not valid command");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
		len = 0;
		line = NULL;
		print_sign();
	}
	exit(EXIT_SUCCESS);
}
