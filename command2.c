#include "shell.h"
int _write(int file_descriptor, const char *str, size_t len) {
    return write(file_descriptor, str, len);
}

int _access(const char *path, int mode) {
    return access(path, mode);
}

int _execvp(const char *file, char *const argv[]) {
    return execvp(file, argv);
}

pid_t _fork(void) {
    return fork();
}

void _wait(int *status) {
    wait(status);
}

int _WIFEXITED(int status) {
    return WIFEXITED(status);
}
