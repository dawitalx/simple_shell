#include "shell.h"

int _WEXITSTATUS(int status)
{
	return (WEXITSTATUS(status));
}

void _exit(int status)
{
	exit(status);
}

void execute_command(char *input) 
{
	char **args = split_input(input);

	if (command_exists(args[0])) 
	{
		pid_t child_pid = _fork();

		if (child_pid == -1) 
		{
			_stringprint("fork error\n");
			_exit(EXIT_FAILURE);
		}

		if (child_pid == 0) 
		{
			if (_execvp(args[0], args) == -1) 
			{
				_stringprint("execvp error\n");
				_exit(EXIT_FAILURE);
			}
		} 
		else 
		{
			int status;
			int exit_status;

			_wait(&status);
			exit_status = _WEXITSTATUS(status);

			if (_WIFEXITED(status) && exit_status != 0) 
			{
				_stringprint("Command execution failed with exit status");
				_putchar(exit_status + '0');
				_stringprint("\n");
			}

			free(args);
		}
	} 
	else 
	{
		_stringprint("Command not found: ");
		_stringprint(args[0]);
		_stringprint("\n");
		free(args);
	}
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
