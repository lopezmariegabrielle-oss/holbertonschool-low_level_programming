#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring, or NULL
 */
char *_strstr(char *haystack, char *needle)
{
int i = 0;
int j;
if (*needle == '\0')
return (haystack);

while (haystack[i] != '\0')
{
j = 0;
while (haystack[i + j] == needle[j] && needle[j] != '\0')
{
j++;
}
if (needle[j] == '\0')
{
return (&haystack[i]);
}
i++;
}
return (NULL);
}
