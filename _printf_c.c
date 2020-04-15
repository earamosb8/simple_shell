#include "shell.h"
/**
 * _printc - Print char
 * @c: char of the va_list
 * Return: count + 1
 */
int _printc(va_list c)
{
	return (_putchar(va_arg(c, int)));
}
/**
 * _prints - Print string
 * @s: string
 * Return: count + lenght
 */
int _prints(va_list s)
{
	int i, count = 0;
	char *ptr = va_arg(s, char *);

	if (ptr == NULL)
	{
		return (write(1, "(null)", 6));
	}
	for (i = 0; ptr[i]; i++, count++)
	{
		_putchar(ptr[i]);
	}
	return (count);
}
