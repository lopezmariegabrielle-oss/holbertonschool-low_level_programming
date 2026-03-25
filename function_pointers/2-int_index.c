#include "function_pointers.h"
#include <stddef.h>
/**
 * int_index - searches for an integer
 * @array: the array to search in
 * @size: number of elements in the array
 * @cmp: pointer to the function to be used to compare values
 *
 * Return: index of the first element for which cmp doesn't return 0,
 * or -1 if no match or size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
int i = 0;
if (array == NULL || cmp == NULL || size <= 0)
{
return (-1);
}
while (i < size)
{
if (cmp(array[i]) != 0)
{
return (i);
}
i++;
}
return (-1);
}
