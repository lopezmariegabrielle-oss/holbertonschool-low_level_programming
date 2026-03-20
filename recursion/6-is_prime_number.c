#include "main.h"

/**
 * check_prime - vérifie récursivement les diviseurs
 * @n: le nombre à tester
 * @i: le diviseur actuel
 *
 * Return: 1 si premier, 0 sinon
 */
int check_prime(int n, int i)
{
if (i == n)
{
return (1);
}
if (n % i == 0)
{
return (0);
}
return (check_prime(n, i + 1));
}
/* fonction d'entréé */
int is_prime_number(int n)
{
if (n <= 1)
{
return (0);
}
return (check_prime(n, 2));
}
