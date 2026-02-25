#include <stdio.h>
#include "main.h"
/**
* _abs - calcule la valeur absolue d'un entier
* @n: l'entier à transformer
*
* Return: la valeur absolue de n
*/

int _abs(int n)
{
if (n < 0)
{
n = n * -1;
}
return (n);
}
