#include "shell.h"
/**
 * _strcpy - copy str and null byte from src to dest
 * @dest: copy of the string
 * @src: string to copy
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
