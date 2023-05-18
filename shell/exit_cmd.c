#include "shell.h"

void exit_hdl(char *command)
{
	if (_strcmp(command, "exit") == 0)
	{
		free(command);
		exit(0);
	}
}
