#include "shell.h"

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}


char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
char *_strdup(const char *str)
{
	char *s;
	int l = 0;
	if (str == NULL)
		return (NULL);
	while (*str++)
		l++;
	s = malloc(sizeof(char) * (l + 1));
	if (!s)
		return (NULL);
	for (l++; l--;)
		s[l] = *--str;
	return (s);
}

