#include "shell.h"

void print_environment()
{
    char **env = environ;

    while (*env != NULL)
    {
        _puts(*env);
		_puts("\n");
        env++;
    }
}
