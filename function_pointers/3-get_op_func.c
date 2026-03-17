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
        /* j'utilise s[1] == '\0' pour m'assurer que l'opérateur fait 1 seul caractère */
        if (strcmp(ops[i].op, s) == 0 && s[1] == '\0')
            return (ops[i].f);
        i++;
    }
    return (NULL);
}
