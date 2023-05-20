#include "shell.h"
int _putchar(char c)
{
	return (write(1, &c, 1));
}

char *_strcpy(char *dest, char *src)
{
	int i = 0;
	while (dest[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}


void _puts(char *str)
{
	int i = 0;
if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
char *_getenv(char *name)
{
	int i = 0;

	for (; environ[i]; i++)
	{
		char *env_name = environ[i];

		if (_strncmp(env_name, name, _strlen(name)) == 0)
		{
			
			return _strchr(env_name, '=') + 1;
		}
	}

	return NULL;
}
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

