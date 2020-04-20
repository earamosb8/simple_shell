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
	const char *delim_line = " \t\n\r";
	const char delim_lot = ' ';
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status, counter = 0;
	char **command = NULL;

	(void) argc;
	signal(SIGINT, c_handler);
	print_sign();
	while ((read = getline(&line, &len, stdin)))
	{
		if (read == EOF)
			read_error(line);
		counter++;
		if (*line != '\t' || *line  != '\n')
		{
			token = tokenize(line, delim_line, delim_lot);
			if (token != NULL)
			{
				child_pid = fork();
				if (child_pid == -1)
					exit(EXIT_FAILURE);
				if (child_pid == 0)
					ejecutador(token, line, argv, env, counter, command);
				else
				{
					wait(&status);
					if ((_strcmp(token[0], "exit") == 0))
						send_free(line, token), exit(EXIT_SUCCESS);
					else
						send_free(line, token), free_all(command);
				}
			}
		}
		len = 0, line = NULL, print_sign();
	}
	exit(EXIT_SUCCESS);
}
