#include "main.h"
#include <stddef.h>

/**
 * _strcat - Concatène deux chaînes de caractères.
 * @dest: La chaîne de destination (doit avoir assez d'espace).
 * @src: La chaîne source à ajouter.
 *
 * Return: Un pointeur vers la chaîne de destination dest.
 */
char *_strcat(char *dest, char *src)
{
int i = 0;
int j = 0;

if (dest == NULL || src == NULL)
return (dest);

while (dest[i] != '\0')
{
i++;
}
while (src[j] != '\0')
{
dest[i] = src[j];
i++;
j++;
}
dest[i] = '\0';
return (dest);
}
