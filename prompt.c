#include "shell.h"
/**
 * main - fork & wait example
 * @argc: void arg
 * @env: eviroment
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *env[])
{
	char *line = NULL, **token;
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status;
	int counter = 0;

	(void) argc;
	print_sign();
	while ((read = getline(&line, &len, stdin)))
	{
		if (read == EOF)
		{
			perror("Unable to allocate buffer");
			free(line);
			return (EXIT_FAILURE);
		}
		counter ++;

		if (*line != '\n')
		{
			token = tokenize(line);
			if ((_strcmp("exit",token[0]) == 0))
			{
				free(line);
				free_all(token);
				exit(EXIT_SUCCESS);
			}
			child_pid = fork();

			if (child_pid == -1)
			{
				exit(EXIT_FAILURE);
			}
			if (child_pid == 0)
			{
				if (token == NULL)
				{
					free(line);
					exit(EXIT_SUCCESS);
				}
				else if (execve(token[0], token, env) == -1)
				{
					print_error(argv, counter, token[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(&status);
				send_free(line, token);
			}
		}
		
		len = 0, line = NULL;
		print_sign();
	}
	exit(EXIT_SUCCESS);
}
