#include "shell.h"
/**
 * main - fork & wait example
 * @argc: void arg
 * @env: eviroment
 * Return: Always 0.
 */
int main(int argc, char *env[])
{
	char *line = NULL, **token;
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status;
	(void) argc;

	print_sign();
	while ((read = getline(&line, &len, stdin)))
	{
		if (read < 0)
		{
			perror("Unable to allocate buffer");
			return (EXIT_FAILURE);
		}
		token = tokenize(line);
		if ((_strcmp(token[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		child_pid = fork();
		if ((child_pid) == 0)
		{
			if (execve(token[0], token, env) == -1)
			{
				perror("Error: not valid command");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
		len = 0;
		line = NULL;
		print_sign();
	}
	exit(EXIT_SUCCESS);
}
