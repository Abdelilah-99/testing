#include "myshell.h"

char *get_token(char *command)
{
	char *token;

	token = strtok(command, "");
	if (token == NULL)
	{
		return NULL; // Empty command
	}

	return token;
}
