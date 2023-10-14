#include "shell.h"

int command_exists(char command);
{
	char path = getenv("PATH");
	char path_copy[MAX_PATH];
	strncpy (path_copy,path,sizeof(path_copy));
	char *token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char full_path[MAX_PATH];
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			return (1); //Command exists//
		}
		token = strtok(NULL, ":");
	}
	return (0);
}
