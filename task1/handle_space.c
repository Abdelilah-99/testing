#include "myshell.h"

char *triming_whitespace(char *str)
{
    int start = 0, end = strlen(str) - 1;
    int i;

    while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
        start++;

    while (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')
        end--;

    for (i = 0; i <= end - start; i++)
        str[i] = str[start + i];

    str[i] = '\0';

    return str;
}
