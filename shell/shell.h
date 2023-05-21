#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define LENGTH 50
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
extern char **environ;
int _strlen(char *s);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
char *_getenv(char *name);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
void print_environment();
void trim_whitespace(char *str);
void execute_command(char *command);
char *find_command_path(char *command, char *path);
void run_shell();
char* traverse_path(char* command, char* path);
void print_exit(char* arr[]);
int _atoi(char *s);
<<<<<<< HEAD
=======
int is_delimiter(char c, char *delim);
char *_strtok(char *str, char *delim);
int _strncmp(char *s1, char *s2, size_t n);
char *_strchr(char *str, int c);
>>>>>>> 18722acfea4c956c3e0f431883a56556f08fab32

#endif
