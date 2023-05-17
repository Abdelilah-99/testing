#include "myshell.h"

char *get_token(char *command)
{
	char *token;
	char *arguments[MAX_ARGUMENTS];
	int i;

	token = strtok(command, " ");

	while (token != NULL && i < MAX_ARGUMENTS - 1)
	{
		arguments[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	arguments[i] = NULL;
	return (token);
}
