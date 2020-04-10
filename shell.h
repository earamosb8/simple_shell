#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
char buffer[1024];
int _putchar(char c);
int _printf(const char *format, ...);
int (*get_op_func(const char *s))(va_list);
int _printc(va_list c);
int _printp(__attribute__((unused))va_list c);
int _prints(va_list s);
int _printd(va_list d);
int _printi(va_list i);
/**
 * struct format - Struct to define type of data and its function.
 * @type: formats
 * @f: The function associated
 * Description: structure functions
 */
typedef struct format
{
	char *type;
	int (*f)(va_list);
} listype;

void print_sign(void);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char **tokenize(char *line);
unsigned int command_lot(char *str);
char *_strncpy(char *dest, char *src, int n);
void free_all(char **com);

#endif
