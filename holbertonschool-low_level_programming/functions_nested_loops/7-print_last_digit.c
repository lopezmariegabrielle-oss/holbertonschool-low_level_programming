#include <stdio.h>
#include "main.h"
/**
 * print_last_digit - affiche et renvoie le dernier chiffre d'un nombre
 * @n: le nombre à traiter
 *
 * Return: la valeur du dernier chiffre
 */
int print_last_digit(int n)
{
int last;
last = n % 10;
if (last < 0)
{
last = -last;
}
_putchar(last + '0');
return (last);
}
