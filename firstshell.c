#include "shell.h"
/**
 * main - simple shell
 * Return: 0
 */

int main(void)
{
	char input[MAX_INPUT];
	pid_t child_pid, status;
	int exit_status;
	char *argv[2];

	argv[0] = input;
	argv[1] = NULL;

	while (1)
	{
		_stringprint("$");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			_stringprint("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';

		child_pid = fork();

		if (child_pid == -1)
		{
			_stringprint("fork error\n");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			if (execve(input, argv, NULL) == -1)
			{
				_stringprint("execve error\n");
				exit(EXIT_FAILURE);
			}
		} else
		{
			wait(&status);
			exit_status = WEXITSTATUS(status);

			if (WIFEXITED(status) && exit_status != 0)
			{
				_stringprint("Command execution failed with exit status");
				_putchar(exit_status + '0');
				_stringprint("\n");
			}
		}
	}

	return (0);
}
