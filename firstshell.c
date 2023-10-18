#include "shell.h"

int command_exists(char *command)
{
	char *path = getenv("PATH");
	char path_copy[MAX_PATH];
	size_t i;

	for (i = 0; i < MAX_PATH; i++)
	{
		if (path[i] == '\0')
		{
			path_copy[i] = '\0';
			break;
		}
		path_copy[i] = path[i];
	}

	for (i = 0; i < MAX_PATH; i++)
	{
		char *token = strtok(path_copy, ":");
		while (token != NULL)
		{
			char full_path[MAX_PATH];
			size_t j;

			for (j = 0; j < MAX_PATH; j++)
			{
				if (token[j] == '\0')
				{
					full_path[j] = '/';
					break;
				}
				full_path[j] = token[j];
			}
			for (j = 0; j < MAX_PATH; j++)
			{
				if (command[j] == '\0')
				{
					full_path[j + 1] = '\0';
					break;
				}
				full_path[j + 1] = command[j];
			}
			if (_access(full_path, X_OK) == 0)
			{
				return (1);
			}
			token = strtok(NULL, ":");
		}
	}
	return (0);
}

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

/**
 * main - simple shell
 * Return: 0
 */

int main(void)
{
	size_t len = 0;
	char input[MAX_INPUT];

	while (1)
	{
		_stringprint("$");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			_stringprint("\n");
			exit_shell();
		}

		len = _strlen(input);
		if (input[len - 1] == '\n')
		{
			input[len - 1] = '\0';
		}

		if (_strcmp(input, "exit") == 0)
		{
			exit_shell();
		}
		else if (_strcmp(input, "env") == 0)
		{
			print_environment();
		}
		else
		{
			execute_command(input);
		}
	}

	return (0);
}
