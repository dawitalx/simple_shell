#include "shell.h"

int _WEXITSTATUS(int status)
{
	return (WEXITSTATUS(status));
}

void _exit(int status)
{
	exit(status);
}

void exit_shell(void)
{
	_exit(EXIT_SUCCESS);
}
void print_environment(void)
{
	extern char **environ;
	int i = 0;
	for (i = 0; environ[i] != NULL; i++)
	{
		_stringprint(environ[i]);
		_stringprint("\n");
	}
}
