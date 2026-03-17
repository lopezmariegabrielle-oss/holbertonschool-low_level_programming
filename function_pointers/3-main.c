#include "3-calc.h"

int main(int argc, char *argv[])
{
    int num1, num2;
    int (*func)(int, int);

    /* je verifie le nombre d'arguments */
    if (argc != 4)
    {
        printf("Error\n");
        exit(98);
    }

    /* je récupère la fonction correspondant à l'opérateur */
    func = get_op_func(argv[2]);

    /* je verifie si l'opérateur est valide */
    if (func == NULL)
    {
        printf("Error\n");
        exit(99);
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[3]);

    /* je verifie la division par zéro */
    if ((strcmp(argv[2], "/") == 0 || strcmp(argv[2], "%") == 0) && num2 == 0)
    {
        printf("Error\n");
        exit(100);
    }

    printf("%d\n", func(num1, num2));
    return (0);
}
