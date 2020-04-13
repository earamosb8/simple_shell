#include "shell.h"
/**
 * print_sign - Function to print the sign
 * Return: Nothing(void)
 */
void print_sign(void)
{
	char *prompt = "#cisfun$ ";
	int len = _strlen(prompt);

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, len);
}
/**
 * tokenize - convert string on intems of an array
 * @line: string to tokenize
 * Return: array of strings
 */
char **tokenize(char *line)
{
	char *token;
	char **command;
	unsigned int len;
	int i = 0;

	line[_strlen(line) - 1] = '\0';
	len = command_lot(line);
	if (len == 0)
		return (NULL);

	command = malloc((sizeof(char *) * (len + 1)));
	if (command == NULL)
		return (NULL);

	token = strtok(line, " \t\n\r");
	while (token != NULL)
	{
		command[i] = malloc(_strlen(token) + 1);
		if (command[i] == NULL)
		{
			free_all(command);
			return (NULL);
		}
		_strncpy(command[i], token, _strlen(token) + 1);
		token = strtok(NULL, " \t\n\r");
		i++;
	}
	command[i] = NULL;
	return (command);
}

/**
 * fun_per - free line
 * @line: string to free
 *
 * Return: (EXIT_FAILURE).
 */
int fun_per (char * line)
{
	perror("Unable to allocate buffer");
	free(line);
	return (EXIT_FAILURE);
}
