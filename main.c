#include "shell.h"
/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(int argc,char *argv[], char *env[])
{
	char *line = NULL;
	char *token = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status, i = 0;
    (void)argc;

	print_sign();
	while ((read = getline(&line, &len, stdin)))
	{
		if (read < 0)
		{
			perror("Unable to allocate buffer");
			free(line);
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
		free(line);
		len = 0;
		line = NULL;
		print_sign();
	}
	return (EXIT_SUCCESS);
}
