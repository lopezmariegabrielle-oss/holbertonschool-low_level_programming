#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to evaluate
 * @accept: string containing the list of characters to match
 *
 * Return: the number of bytes in the initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int i = 0;
unsigned int j;
unsigned int count = 0;
int found;

while (s[i] != '\0')
{
found = 0;
j = 0;

while (accept[j] != '\0')
{
if (s[i] == accept[j])
{
found = 1;
break;
}
j++;
}

if (found == 0)
{
return (count);
}

count++;
i++;
}

return (count);
}
