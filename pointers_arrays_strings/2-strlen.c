#include "main.h"
/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
    int longueur = 0;

    if (s == NULL)
	{
		return (0);
	}
while (s[longueur] != '\0')
{
    longueur++;
}

return (longueur);
}
