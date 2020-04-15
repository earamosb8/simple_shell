#include "shell.h"
/**
 * c_handler - handle the ctrl + c
 * @next: non used argument
 * Return: void
 */
void c_handler (int next)
{
	(void) next;
	_printf("\n#cisfun$ ");
}
/**
 * main - fork & wait example
 * @argc: void arg
 * @env: eviroment
 * @argv: arguments
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

	signal(SIGINT, c_handler);

	print_sign();
	while ((read = getline(&line, &len, stdin)))
	{
		if (read == EOF)
			fun_per(line);
		counter++;
		if (*line  != '\n')
		{
			token = tokenize(line);
			if (token != NULL)
			{
			child_pid = fork();
			if (child_pid == -1)
				exit(EXIT_FAILURE);
			if (child_pid == 0)
				ejecutador(token, line, argv, env, counter);
			else
			{
				wait(&status);
				if ((_strcmp(token[0], "exit") == 0))
					send_free(line, token), exit(EXIT_SUCCESS);
				else
					send_free(line, token);
			}
			}
		}
		len = 0, line = NULL, print_sign();
	}
	exit(EXIT_SUCCESS);
}
