#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * @n: maximum number of bytes from s2 to concatenate.
 *
 * Return: pointer to the newly allocated space in memory.
 * if the function fails, it should return NULL.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *s;
unsigned int len1 = 0, len2 = 0, i, j;
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";
/*comtage de s1*/
while (s1[len1] != '\0')
{
len1++;
}
/*contage de s2*/
while (s2[len2] != '\0')
{
len2++;
}
if (n >= len2)
n = len2;

s = malloc(sizeof(char) * (len1 + n + 1));
if (s == NULL)
return (NULL);

/*copie s1 dans s*/
i = 0;
while (i < len1)
{
s[i] = s1[i];
i++;
}
/*copie s2 dans s*/
j = 0;
while (j < n)
{
s[i] = s2[j];
i++;
j++;
}
s[i] = '\0';/*fermeture de la chaine*/
return (s);
}
