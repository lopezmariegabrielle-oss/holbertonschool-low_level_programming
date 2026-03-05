#include "main.h"

/**
 * _strcmp - Compare deux chaînes de caractères.
 * @s1: La première chaîne.
 * @s2: La seconde chaîne.
 *
 * Return: La différence ASCII entre les premiers caractères différents.
 */
int _strcmp(char *s1, char *s2)
{
int i = 0;

if (s1 == NULL || s2 == NULL)
return (0);
while (s1[i] != '\0' && s1[i] == s2[i])
{
i++;
}
return (s1[i] - s2[i]);
}
