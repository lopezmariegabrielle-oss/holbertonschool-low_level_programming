#include "main.h"
/**
 * _memset - remplit la mémoire avec un octet constant
 * @s: zone mémoire à remplir
 * @b: octet constant
 * @n: nombre d'octets à remplir
 *
 * Return: pointeur vers la zone mémoire s
 */

char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

i = 0;
while (i < n)
{
s[i] = b;
i++;
}
return (s);
}
