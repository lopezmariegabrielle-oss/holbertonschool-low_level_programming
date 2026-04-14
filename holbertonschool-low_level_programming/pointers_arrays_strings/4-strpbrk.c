#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to search
 * @accept: the bytes to look for
 *
 * Return: a pointer to the byte in s that matches, or NULL if not found
 */
char *_strpbrk(char *s, char *accept)
{
int i = 0;
int j;

while (s[i] != '\0')
{
j = 0;
while (accept[j] != '\0')
{
if (s[i] == accept[j])
{
return (&s[i]);
}
j++;
}
i++;
}

return (NULL);
}
