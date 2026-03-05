#include "main.h"

/**
 * leet - Encode une chaîne de caractères en 1337.
 * @s: La chaîne à encoder.
 *
 * Return: Un pointeur vers la chaîne modifiée.
 */
char *leet(char *s)
{
int i, j;
char s1[] = "aeotlAEOTL";
char s2[] = "4307143071";

if (s == NULL)
return (NULL);

i = 0;
while (s[i] != '\0')
{
j = 0;
while (s1[j] != '\0')
{
if (s[i] == s1[j])
{
s[i] = s2[j];
break;
}
j++;
}
i++;
}
return (s);
}
