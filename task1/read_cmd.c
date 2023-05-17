#include "myshell.h"

char *read_command(void)
{
	char *command = NULL;
	size_t command_length = 0;
	ssize_t characters_read;

	printf("$ ");
	command = malloc(MAX_COMMAND_LENGTH * sizeof(char));
	if (command == NULL)
	{
		return NULL;
	}
	characters_read = getline(&command, &command_length, stdin);
	if (characters_read == -1)
	{
		// Handle end of file condition (Ctrl+D)
		free(command);
		return NULL;
	}

	return command;
}
