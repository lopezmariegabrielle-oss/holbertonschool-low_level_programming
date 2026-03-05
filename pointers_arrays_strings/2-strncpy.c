#include "main.h"

/**
 * _strncpy - Copie une chaîne dans une autre.
 * @dest: La destination.
 * @src: La source.
 * @n: Le nombre d'octets à copier.
 *
 * Return: Un pointeur vers dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
int i = 0;

if (dest == NULL || src == NULL)
return (dest);

while (i < n && src[i] != '\0')
{
dest[i] = src[i];
i++;
}
while (i < n)
{
dest[i] = '\0';
i++;
}
return (dest);
}
