#include "shell.h"
/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(int ac, char *env[])
{
	char *line = NULL;
	char *token = NULL, *argv[32];
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status, i = 0;

	ac = ac;
	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&line, &len, stdin);
		if (read < 0)
		{
			perror("Unable to allocate buffer");
			return (EXIT_FAILURE);
		}
		token = strtok(line, " \t\n\r");
			while (token != NULL)
			{
				argv[i] = token;
				if (_strcmp(argv[0], "exit") == 0)
			{
				exit(EXIT_SUCCESS);
			}
				token = strtok(NULL, " \t\n\r");
			}
			argv[i + 1] = NULL;
		if ((child_pid = fork()) == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				perror("Error:");
			}
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

