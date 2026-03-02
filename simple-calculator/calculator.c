#include <stdio.h>

/**
 * effectuer_calcul - Gère les opérations de calcul
 * @choix: L'opération choisie
 * @a: Premier nombre
 * @b: Deuxième nombre
 */
void effectuer_calcul(int choix, int a, int b)
{
	switch (choix)
	{
	case 1:
		printf("Result: %d\n", a + b);
		break;
	case 2:
		printf("Result: %d\n", a - b);
		break;
	case 3:
		printf("Result: %d\n", a * b);
		break;
	case 4:
		if (b == 0)
			printf("Error: Division by zero\n");
		else
			printf("Result: %d\n", a / b);
		break;
	}
}
int main(void)
{
	int choix, a, b;

	printf("Simple Calculator\n");
	do {
		printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\nChoice: ");
		scanf("%d", &choix);

		if (choix >= 1 && choix <= 4)
		{
			printf("Enter first number: ");
			scanf("%d", &a);
			printf("Enter second number: ");
			scanf("%d", &b);
			effectuer_calcul(choix, a, b);
		}
		else if (choix == 0)
			printf("Bye!\n");
		else
			printf("Invalid choice, please try again.\n");

	} while (choix != 0);

	return (0);
}
