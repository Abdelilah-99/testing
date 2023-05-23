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
	char *line;
	size_t len;
	ssize_t read_bytes;
	char *resized_line;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return -1; // Invalid arguments
	}
	len = 0;
	line = NULL;
	// Read the line using fgets
	read_bytes = getline(&line, &len, stream);

	if (read_bytes != -1)
	{
		// Trim the newline character if present
		if (line[read_bytes - 1] == '\n')
		{
			line[read_bytes - 1] = '\0';
			read_bytes--;
		}

		// Resize the allocated memory to fit the exact size of the line
		resized_line = (char *)realloc(line, read_bytes);
		if (resized_line != NULL)
		{
			line = resized_line;
		}
		else
		{
			free(line);
			return -1; // Memory reallocation failed
		}
	}

	*lineptr = line;
	*n = read_bytes;

	return read_bytes;
}

int is_delimiter(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
		{
			return 1;
		}
		delim++;
	}
	return 0;
}
char *_strtok(char *str, const char *delim)
{
	static char *token = NULL;
	char *start;

	if (str != NULL)
		token = str;
	else if (token == NULL)
		return (NULL);
	// Skip leading delimiters
	while (*token != '\0' && _strchr(delim, *token) != NULL)
		++token;
	if (*token == '\0')
		return (NULL); // No more tokens
	start = token;
	// Find the end of the token
	while (*token != '\0' && _strchr(delim, *token) == NULL)
		++token;
	if (*token != '\0')
		*token++ = '\0'; // Set the delimiter to '\0' and move to the next character
	return (start);
}

