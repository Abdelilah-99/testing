#include "shell.h"
void execute_command(char *command)
{
    char *arguments[MAX_ARGUMENTS], *token, *command_path;
    int i = 0;
    pid_t pid;
    token = strtok(command, " ");
    if (_strcmp(command, "env") == 0)
    {
        print_environment(); 
        return;
    }
    for (; token != NULL && i < MAX_ARGUMENTS - 1; i++)
    {
        arguments[i] = token;
        token = strtok(NULL, " ");
    }
    arguments[i] = NULL;
    command_path = find_command_path(arguments[0], _getenv("PATH"));
    if (command_path == NULL)
    {
        printf("Error: Command not found or not executable: %s\n", arguments[0]);
        return;
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork"), exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execve(command_path, arguments, NULL);
        perror("execve"), exit(EXIT_FAILURE);
    }
    else
        wait(NULL);
}