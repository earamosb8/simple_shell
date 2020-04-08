#include "shell.h"
/**
* print_dollar - Function to print the dollar sign
*Return: Nothing(void)
*/

void print_sign(void)
{
	char *prompt = "#cisfun$ ";
	int  len = _strlen(prompt);

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, len);
}
