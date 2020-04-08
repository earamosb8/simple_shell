#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int _strcmp(char *s1, char *s2);
void print_sign(void);
int _strlen(char *s);

#endif
