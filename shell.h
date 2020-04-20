#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <errno.h>

int _putchar(char c);
int _printf(const char *format, ...);
int (*get_op_func(const char *s))(va_list);
int _prints(va_list s);

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
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char **tokenize(char *line, const char *delim, const char delim_lot);
unsigned int command_lot(char *str, const char delim);
char *_strncpy(char *dest, char *src, int n);
void free_all(char **com);
void print_error(char **argv, unsigned int count, char **token, char *line);
void send_free(char *buffer, char **commands);
int read_error(char *line);
void ejecutador(char **token, char *line, char **argv, char **env, int count ,char **command);
void c_handler (int next);
void search_path(char **token, char *line, char **argv, char **env, int c, char **command);

#endif
