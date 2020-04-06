#include "shell.h"
/**
 * main - fork & wait example
 * @arc: size of aruments
 * @env: arguments
 * Return: Always 0.
 */
int main(int arc, char *env[])
{
	char *line = NULL;
	char *token = NULL, *argv[32];
	char *exit_com = "exit";
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status, i;

	arc = arc;
	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&line, &len, stdin);
		if (read < 0)
		{
			perror("Unable to allocate buffer");
			exit(EXIT_FAILURE);
		}
		token = strtok(line, " \t\n\r");
		for (i = 0; i < 32 && token != NULL; i++)
		{
			argv[i] = token;
			if (_strcmp(argv[0],exit_com) == 0)
			{
				exit(EXIT_SUCCESS);
			}
			token = strtok(NULL, " \t\n\r");
		}
		argv[i + 1] = NULL;
		child_pid = fork();
		if (child_pid  == 0)
		{

			if (execve(argv[0], argv, env) == -1)
				perror("Error:");

		}
		else
		{
			wait(&status);
		}
	}
	free(argv);
	free(line);
	exit(EXIT_SUCCESS);
}
