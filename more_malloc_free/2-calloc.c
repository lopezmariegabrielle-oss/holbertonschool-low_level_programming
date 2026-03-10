#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements in the array
 * @size: size of each element in bytes
 *
 * Return: pointer to allocated memory, or NULL if nmemb/size is 0
 * or if malloc fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
char *p;
unsigned int total_size;
unsigned int i;

if (nmemb == 0 || size == 0)
return (NULL);
/*calcul de la taille totale*/
total_size = nmemb * size;
p = malloc(total_size);

if (p == NULL)
return (NULL);

i = 0;
while (i < total_size)
{
p[i] = 0;
i++;
}
return (p);
}
