#include "main.h"
#include <stddef.h>

/**
 * _strncat - Concatène deux chaînes avec une limite de n octets.
 * @dest: La chaîne de destination.
 * @src: La chaîne source.
 * @n: Le nombre maximum d'octets à copier depuis src.
 *
 * Return: Un pointeur vers dest.
 */
char *_strncat(char *dest, char *src, int n)
{
int i = 0;
int j = 0;

if (dest == NULL || src == NULL)
return (dest);

while (dest[i] != '\0')
{
i++;
}
while (j < n && src[j] != '\0')
{
dest[i] = src[j];
i++;
j++;
}
dest[i] = '\0';
return (dest);
}
