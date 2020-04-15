
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
	if (token != NULL)
	{
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
	return (NULL);
}
/**
 * command_lot - the number of commands
 * @str: string with the commands
 * Return: number of commands
*/
unsigned int command_lot(char *str)
{
	int i = 0;
	int command = 0, temp = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			temp = 1;
		}
		if ((temp == 1 && str[i + 1] == ' ') || (temp == 1 && str[i + 1] == '\0'))
		{
			command += 1;
			temp = 0;
		}
	}
	return (command);
}
