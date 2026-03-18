#include "variadic_functions.h"

/**
 * sum_them_all - Calcule la somme de tous ses paramètres.
 * @n: Le nombre de paramètres.
 * @...: Les nombres à additionner.
 *
 * Return: La somme, ou 0 si n == 0.
 */
int sum_them_all(const unsigned int n, ...)
{
va_list ap;
unsigned int i;
int sum = 0;

/*Vérifier si n est égal à 0 */
if (n == 0)
return (0);

/*la liste variadique*/
va_start(ap, n);
i = 0;
while (i < n)
{
sum += va_arg(ap, int);
i++;
}
va_end(ap);
return (sum);
}
