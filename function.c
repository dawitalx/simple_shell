#include "shell.h"

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int _stringprint(const char *str)
{
	int written = 0;
	while (str[written])
	{
		_putchar(str[written]);
		written++;
	}
	return (written);
}

char **split_input(char *input)
{
	int i = 0;
	int max_args = MAX_INPUT;
	char **args = (char **)malloc(max_args * sizeof(char *));
	char *token = strtok(input, " ");
	if (!args)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	while (token != NULL)
	{
		args[i] = token;
		i++;
		if (i >= max_args)
		{
			max_args *= 2;
			args = (char **)realloc(args, max_args * sizeof(char *));
			if (!args)
			{
				perror("realloc error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}

size_t _strlen(const char *str)
{
	size_t len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}
