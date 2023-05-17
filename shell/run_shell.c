#include "shell.h"
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
