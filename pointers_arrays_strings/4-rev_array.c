#include "main.h"

/**
 * reverse_array - Inverse le contenu d'un tableau d'entiers.
 * @a: Le tableau d'entiers.
 * @n: Le nombre d'éléments dans le tableau.
 */
void reverse_array(int *a, int n)
{
int i = 0;
int j;
int temp;

if (a == NULL || n <= 0)
return;
i = 0;
j = n - 1;

while (i < j)
{
temp = a[i];
a[i] = a[j];
a[j] = temp;

i++;
j--;
}
return;
}
