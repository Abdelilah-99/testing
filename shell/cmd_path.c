#include "shell.h"

char *find_command_path(char *command, char *path)
{
    char command_path[MAX_COMMAND_LENGTH];
    struct stat file_stat;
    char *path_token;
    char *path_copy;
    if (command[0] == '/')
    {
        if (stat(command, &file_stat) == 0)
            return _strdup(command);
        else
            return NULL;
    }
    
    if (path == NULL)
    {
        printf("Error: Failed to get PATH environment variable.\n");
        return NULL;
    }
    
    path_copy = _strdup(path);
    if (path_copy == NULL)
        perror("strdup"), exit(EXIT_FAILURE);

    path_token = strtok(path_copy, ":");
    while (path_token != NULL)
    {
        snprintf(command_path, MAX_COMMAND_LENGTH, "%s/%s", path_token, command);
        if (stat(command_path, &file_stat) == 0 && file_stat.st_mode & S_IXUSR)
        {
            free(path_copy);
            return _strdup(command_path);
        }
        path_token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
