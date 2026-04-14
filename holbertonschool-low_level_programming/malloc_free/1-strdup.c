#include "main.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string,
 * or NULL if str = NULL or insufficient memory was available
 */
char *_strdup(char *str)
{
char *copy;
unsigned int i, len = 0;

if (str == NULL)
return (NULL);

while (str[len] != '\0')
{
len++;
}
copy = malloc((len + 1) * sizeof(char));

if (copy == NULL)
return (NULL);

i = 0;
while (i <= len)
{
copy[i] = str[i];
i++;
}
return (copy);
}
