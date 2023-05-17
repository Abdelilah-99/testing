#include "shell.h"
void print_environment()
{
    char **env = environ;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}
void trim_whitespace(char *str)
{
    int start = 0, end = _strlen(str) - 1;
    int i;
    while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
        start++;

    while (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')
        end--;

    for (i = 0; i <= end - start; i++)
        str[i] = str[start + i];

    str[i] = '\0';
}

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

void run_shell()
{
    char *command = NULL;
    size_t command_length = 0;
    ssize_t characters_read;

   while (1)
{
    printf("$ ");

    characters_read = getline(&command, &command_length, stdin);

    if (characters_read <= 0)
    {
        if (characters_read == -1)
        {
            printf("\n");
        }
        free(command);
        break;
    }
    trim_whitespace(command);

    if (command[0] == '#' || command[0] == '\0')
    {
        continue;
    }

    execute_command(command);
}
}

