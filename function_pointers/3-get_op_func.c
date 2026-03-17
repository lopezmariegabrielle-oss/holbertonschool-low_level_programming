#include "3-calc.h"
/**
 * get_op_func - selects the correct function to perform the operation
 * @s: operator passed as argument
 *
 * Return: pointer to the function that corresponds to the operator
 * or NULL if s does not match
 */

int (*get_op_func(char *s))(int, int)
{
op_t ops[] = {
{"+", op_add},
{"-", op_sub},
{"*", op_mul},
{"/", op_div},
{"%", op_mod},
{NULL, NULL}
};
int i = 0;

/* On parcourt le tableau ops tant qu'on n'est pas au bout */
while (ops[i].op != NULL)
{
/* Si l'opérateur s correspond à celui du tableau */
/* Comparaison stricte de la chaîne entière */
if (strcmp(ops[i].op, s) == 0 && s[1] == '\0')
return (ops[i].f);
i++;
}
return (NULL);
}
