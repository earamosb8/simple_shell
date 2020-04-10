#include "holberton.h"
/**
 * get_op_func - get function print of format select.
 * @s: format
 * Description: select format
 * Return: function or null
 */
int (*get_op_func(const char *s))(va_list)

{
	unsigned int i = 0;
	listype tipo[] = {
		{"s", _prints},
		{"c", _printc},
		{"i", _printi},
		{"d", _printd},
		{"%", _printp},
		{NULL, NULL}
	};
	for (i = 0; tipo[i].type != NULL; i++)
	{
		if (*(tipo[i].type) == *s)
		{
			break;
		}
	}
	return (tipo[i].f);
}
/**
  *_printf - print format
  *@format: input argument
  *Description: print format
  *Return: print
  */
int _printf(const char *format, ...)
{
	int scans = 0;
	int countf = 0;
	va_list funclist;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);

	va_start(funclist, format);

	while (format[scans])
	{
		if (format[scans] != '%')
			countf += _putchar(format[scans]);
		if (format[scans] == '%')
		{
			while ((format[scans + 1]) == ' ')
				scans++;

			if (format[scans + 1] == '\0')
				return (-1);

			f = get_op_func(&format[scans + 1]);

			if (f != NULL)
			{
				countf += f(funclist);
				scans += 1;
			}

			else
			{
				countf += (_putchar(format[scans]));
			}
		}
		scans++;
	}
	va_end(funclist);
	return (countf);
}
