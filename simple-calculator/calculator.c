#include <stdio.h>

/**
 * main - Affiche un menu de calculatrice et gère la sortie
 *
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	int choice = 0;

	printf("Simple Calculator\n");
    printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
	do {
		printf("Choice: ");
		scanf("%d", &choice);
		if (choice == 0)
		{
			printf("Bye!\n");
		}
		else if (choice < 0 || choice > 4)
		{
			printf("Invalid choice");
		}
        else
        {

        }

	} while (choice != 0);

	return (0);
}
