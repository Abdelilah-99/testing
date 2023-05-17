#include "myshell.h"

int main()
{
	char *command;
	char *token;

	while (1)
	{
		command = malloc(MAX_COMMAND_LENGTH * sizeof(char));
		if (command == NULL)
		{
			perror("malloc");
			break;
		}
		command = read_command();
		if (command == NULL)
		{
			break;
		}

		token = triming_whitespace(command);
		if (token == NULL || strlen(token) == 0)
		{
			free(command);
			continue;
		}

		execute_command(token);

		free(command);
	}

	return 0;
}
