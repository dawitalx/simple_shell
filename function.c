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
