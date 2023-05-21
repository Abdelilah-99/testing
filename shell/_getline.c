#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

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
}char *_strtok(char *str, const char *delim)
{
	static char *token = NULL;
	char *start;

	if (str != NULL)
		token = str;
	else if (token == NULL)
		return (NULL);
	while (*token != '\0' && _strchr(delim, *token) != NULL)
		++token;
	if (*token == '\0')
		return (NULL); 
	start = token;
	
	while (*token != '\0' && _strchr(delim, *token) == NULL)
		++token;
	if (*token != '\0')
		*token++ = '\0'; 
	return (start);
}

