#include "shell.h"
/**
 * mainn - simple program that show proccess id
 * Return: 0
 */

int bettybeauty(void)
{
	char pid_str[12];
	int i = 0;

	pid_t pid = getpid();
	_stringprint("Process ID (PID): ");
	while (pid > 0)
	{
		pid_str[i++] = (pid % 10) + '0';
		pid /= 10;
	}

	while (i > 0)
	{
		_putchar(pid_str[--i]);
	}
	_putchar('\n');
	return (0);
}
