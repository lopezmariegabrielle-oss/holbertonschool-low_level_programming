#include "3-calc.h"

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
        /* je vérifie si l'opérateur correspond et s'il ne fait qu'un seul caractère */
        if (*(ops[i].op) == *s && s[1] == '\0')
            return (ops[i].f);
        i++;
    }
    return (NULL);
}
