#include "shell.h"
/**
 * main - simple shell
 * Return: 0
 */

void execute_command(char *input)
{
	char **args = split_input(input);

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		_stringprint("fork error\n");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			_stringprint("execvp error\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;
		int exit_status;

		wait(&status);
		exit_status = WEXITSTATUS(status);

		if (WIFEXITED(status) && exit_status != 0)
		{
			_stringprint("Command execution failed with exit status");
			_putchar(exit_status + '0');
			_stringprint("\n");
		}

		free(args);
	}
}

int main(void)
{
	char input[MAX_INPUTT];
	int len = 0;

	while (1)
	{
		_stringprint("$");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			_stringprint("\n");
			break;
		}

		len = _strlen(input);
		if (input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
		}

		execute_command(input);
	}

	return (0);
}
