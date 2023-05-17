#include "myshell.h"

void execute_command(char *token)
{
	
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		// Child process
		char **argv = malloc(2 * sizeof(char *));
		if (argv == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		argv[0] = token;
		argv[1] = NULL;

		execve(token, argv, NULL);

		// execve only returns if an error occurs
		perror("execve");
		free(argv); // Free argv if execve fails
		exit(EXIT_FAILURE);
	}
	else
	{
		// Parent process
		wait(NULL);
	}
}
