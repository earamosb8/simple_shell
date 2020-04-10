#include "holberton.h"
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
/**
 * _printp - function that prints percentage sign
 * @c: %
 * Return: numbesr of printed chars
 */
int _printp(__attribute__((unused))va_list c)
{
	return (_putchar('%'));
}
/**
* _printd - print d
* @d: integer
* Return: count
*/
int _printd(va_list d)
{
	int dig[10];
	int i, pow, num, sum, count;

	num = va_arg(d, int);
	count = 0;
	pow = 1000000000;
	dig[0] = num / pow;
	for (i = 1; i < 10; i++)
	{
		pow /= 10;
		dig[i] = (num / pow) % 10;
	}
	if (num < 0)
	{
		_putchar('-');
		count++;
		for (i = 0; i < 10; i++)
			dig[i] *= -1;
	}
	for (i = 0, sum = 0; i < 10; i++)
	{
		sum += dig[i];
		if (sum != 0 || i == 9)
		{
			_putchar(dig[i] + '0');
			count++;
		}

	}
	return (count);
}
/**
* _printi - print integer
* @i: integer
* Return: count
*/
int _printi(va_list i)
{
	int dig[10];
	int j, pow, num, sum, count;

	num = va_arg(i, int);
	count = 0;
	pow = 1000000000;
	dig[0] = num / pow;
	for (j = 1; j < 10; j++)
	{
		pow /= 10;
		dig[j] = (num / pow) % 10;
	}
	if (num < 0)
	{
		_putchar('-');
		count++;
		for (j = 0 ; j < 10; j++)
			dig[j] *= -1;
	}
	for (j = 0, sum = 0; j < 10; j++)
	{
		sum += dig[j];
		if (sum != 0 || j == 9)
		{
			_putchar(dig[j] + '0');
			count++;
		}

	}
	return (count);
}
