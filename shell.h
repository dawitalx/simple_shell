#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_INPUTT 1024

int _putchar(char c);
int _stringprint(const char *str);
int bettybeauty(void);
char **split_input(char *input);
void execute_command(char *input);
size_t _strlen(const char *str);

#endif /* SHELL_H */

