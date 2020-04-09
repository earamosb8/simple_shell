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

void print_sign(void);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char **tokenize(char *line);
unsigned int command_lot(char *str);
char *_strncpy(char *dest, char *src, int n);
void free_all(char **com);

#endif
