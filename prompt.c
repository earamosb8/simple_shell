#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
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
			return (EXIT_FAILURE);
		}
		token = strtok(line, " \t\n\r");
		for (i = 0; i < 32 && token != NULL; i++)
		{
			argv[i] = token;
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
