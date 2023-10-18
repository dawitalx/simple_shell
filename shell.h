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
#define MAX_PATH 1024

int _putchar(char c);
int _stringprint(const char *str);
int bettybeauty(void);
char **split_input(char *input);
void execute_command(char *input);
size_t _strlen(const char *str);
int _write(int file_descriptor, const char *str, size_t len);
int _access(const char *path, int mode);
int _execvp(const char *file, char *const argv[]);
pid_t _fork(void);
void _wait(int *status);
int _WIFEXITED(int status);
int _WEXITSTATUS(int status);
void _exit(int status);
int command_exists(char *command);
void exit_shell(void);
void print_environment(void);
int _strcmp(const char *s1, const char *s2);

#endif /* SHELL_H */

