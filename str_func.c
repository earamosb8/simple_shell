#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strcmp - writes the character c to stdout
 * @s1: The character to print
 * @s2: dsfsdfsdfsdfd
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _strcmp(char *s1, char *s2)
{
	int a = 0;

	while (s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0')
	{
		a++;
	}

	return (s1[a] - s2[a]);
}
/**
 * _strlen - show length of string
 * @s: character
 * Description: Show lenght of string
 * Return: value of lenght
 */
int _strlen(char *s)
{
	int i;

	for (i = 0 ; s[i] != '\0' ; i++)
	{
		;
	}
	return (i);
}
/**
 * _strncpy - copy str and null byte from src to dest
 * @dest: copy of the string
 * @src: string to copy
 * @n: integer number
 * Return: string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for ( ; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
