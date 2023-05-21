#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
/**
 * _getline - get a strin from stdint
 * @lineptr: double pointer to char
 * @n: skjf
 * @stream: the type of std
 * Return: mul
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	size_t i;
	size_t size;
	char *new_lineptr = NULL;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	i = 0;
	size = *n;
	if (*lineptr == NULL)
	{
		size = 128;
		*lineptr = (char *)malloc(size);
		if (*lineptr == NULL)
			return (-1);
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= size - 1)
		{
			size *= 2;
			new_lineptr = (char *)realloc(*lineptr, size);
			if (new_lineptr == NULL)
			{
				free(*lineptr);
				*lineptr = NULL;
				return (-1);
			}
			*lineptr = new_lineptr;
		}
		(*lineptr)[i++] = (char)c;
		if (c == '\n')
			break;
	}
	(*lineptr)[i] = '\0';
	*n = size;
	if (i == 0 && c == EOF)
		return (-1);
	return ((ssize_t)i);
}
int is_delimiter(char c, char *delim) {
    while (*delim != '\0') {
        if (c == *delim) {
            return 1;
        }
        delim++;
    }
    return 0;
}

char *_strtok(char *str, char *delim) {
    static char *token = NULL;
    static char *next_token = NULL;
    char *start = NULL;
    char *end = NULL;
    if (str != NULL) {
        token = str;
        next_token = NULL;
    }
    if (token == NULL) {
        return NULL;
    }
    
    start = token;
    
    while (*token != '\0') {
        if (is_delimiter(*token, delim)) {
            *token = '\0';
            end = token;
            token++;
            break;
        }
        token++;
    }
    
    if (end == NULL) {
        end = token;
    }
    
    if (*token == '\0') {
        token = next_token;
    }
    else {
        next_token = token;
    }
    
    return start;
}
