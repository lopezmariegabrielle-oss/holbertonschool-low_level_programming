#include "main.h"

/**
 * _pow_recursion - returns the value of x raised to the power of y
 * @x: the base value
 * @y: the power to raise x to
 *
 * Return: x to the power of y, or -1 if y < 0
 */
int _pow_recursion(int x, int y)
{
if (y < 0) /* erreur pour les exposants négatif */
{
return (-1);
}
if (y == 0) /* cas de base */
{
return (1);
} /* cas récursif x * (x puissance y-1) */
return (x * _pow_recursion(x, y - 1));
}
