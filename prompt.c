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
	char *line = NULL, *token, *argv[32]; /** se cambiaria el *token por **token para la funcion tokenize(); y se eliminaria el argv*/
	size_t len = 0;
	ssize_t read;
	pid_t child_pid;
	int status, i = 0; /** se eliminaria el i = 0, no se necesitaria en la tokenize(); */
	(void) argc;

	print_sign();

	while ((read = getline(&line, &len, stdin)))
	{
		if (read < 0)
		{
			perror("Unable to allocate buffer");
			return (EXIT_FAILURE);
		}

/*		token = tokenize(line); */

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
		i = 0;/** hasta aca iria la funcion de tokenizar */
		
		child_pid = fork();
		if ((child_pid) == 0)
		{
			if (execve(argv[0], argv, env) == -1) /** aca tendriamos q cambiar el argv[i] por token[i] y argv por token */
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
