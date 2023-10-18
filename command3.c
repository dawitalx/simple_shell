#include "shell.h"

int _WIFEXITED(int status)
{
	return (WIFEXITED(status));
}
