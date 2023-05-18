#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024

extern char **environ;
int _strlen(char *s);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
void print_environment();
void trim_whitespace(char *str);
void execute_command(char *command);
char *find_command_path(char *command, char *path);
void run_shell();
void exit_hdl(char *command);
char* traverse_path(char* command, char* path);

#endif
