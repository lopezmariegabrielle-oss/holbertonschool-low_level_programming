#include "function_pointers.h"
#include <stddef.h>
/**
 * array_iterator - executes a function on each element of an array
 * @array: the array to iterate over
 * @size: size of the array
 * @action: pointer to the function to use
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
size_t i = 0;

if (array != NULL && action != NULL)
{
while (i < size)
{
action(array[i]);
i++;
}
}
}
