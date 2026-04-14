#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * array_range - creates an array of integers
 * @min: the minimum value to include
 * @max: the maximum value to include
 *
 * Return: pointer to the newly created array,
 * NULL if min > max or if malloc fails
 */
int *array_range(int min, int max)
{
int *array;
int i, size;

if (min > max)
return (NULL);
/*calcule du nombre d'elements*/
size = (max - min) + 1;

array = malloc(sizeof(int) * size);

if (array == NULL)
return (NULL);

i = 0;
while (i < size)
{
array[i] = min + i;
i++;
}
return (array);
}
