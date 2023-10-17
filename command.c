#include "shell.h"

int _WEXITSTATUS(int status) {
    return WEXITSTATUS(status);
}

void _exit(int status) {
    exit(status);
}

int command_exists(char *command) {
    char *path = getenv("PATH");
    char path_copy[MAX_PATH];
    for (size_t i = 0; i < MAX_PATH; i++) {
        if (path[i] == '\0') {
            path_copy[i] = '\0';
            break;
        }
        path_copy[i] = path[i];
    }
    char *token = strtok(path_copy, ":");
    while (token != NULL) {
        char full_path[MAX_PATH];
        for (size_t i = 0; i < MAX_PATH; i++) {
            if (token[i] == '\0') {
                full_path[i] = '/';
                break;
            }
            full_path[i] = token[i];
        }
        for (size_t i = 0; i < MAX_PATH; i++) {
            if (command[i] == '\0') {
                full_path[i + 1] = '\0';
                break;
            }
            full_path[i + 1] = command[i];
        }
        if (_access(full_path, X_OK) == 0) {
            return 1; 
        }
        token = strtok(NULL, ":");
    }
    return 0; 
}


void exit_shell() {
    _exit(EXIT_SUCCESS);
}
void print_environment() {
    extern char **environ;
    for (int i = 0; environ[i] != NULL; i++) {
        _stringprint(environ[i]);
        _stringprint("\n");
    }
}
