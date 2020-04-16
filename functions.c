
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
 * @delim: delimiter to tokenize
 * @delim_lot: delimiter to command_lot
 * Return: array of strings
 */
char **tokenize(char *line, const char *delim, const char delim_lot)
{
	char *token;
	char **command;
	unsigned int len;
	int i = 0;

	line[_strlen(line) - 1] = '\0';
	len = command_lot(line, delim_lot);
	if (len == 0)
		return (NULL);

	command = malloc((sizeof(char *) * (len + 1)));
	if (command == NULL)
		return (NULL);
	token = strtok(line, delim);
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
			token = strtok(NULL, delim);
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
 * @delim: delimiter char from command_lot function
 * Return: number of commands
*/
unsigned int command_lot(char *str, const char delim)
{
	int i = 0;
	int command = 0, temp = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != delim)
		{
			temp = 1;
		}
		if ((temp == 1 && str[i + 1] == delim) || (temp == 1 && str[i + 1] == '\0'))
		{
			command += 1;
			temp = 0;
		}
	}
	return (command);
}
/**
 * _realloc - change the memory alocated
 * @ptr: pointer to the memory allocated
 * @old_size: size on bits
 * @new_size: new size of bits
 * Description: change the size of the memory
 * Return: void
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void  *newptr;

	if (ptr == NULL)
	{
		newptr = (malloc(new_size));
		return (newptr);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	newptr = malloc(new_size);
	if (newptr == NULL)
	{
		return (NULL);
	}
	_memcpy(newptr, ptr, old_size);
	free(ptr);
	return (newptr);
}
/**
 * _memcpy - copy str the number of bytes from src to dest
 * @dest: copy of the string
 * @src: string to copy
 * @n: integer number
 * Return: char dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
