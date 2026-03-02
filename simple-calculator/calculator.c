#include <stdio.h>

/**
 * main - Point d'entrée pour la calculatrice
 *
 * Return: Toujours 0
 */
int main(void)
{
int choix;
while (choice != 0 || choice != 1 || choice != 2 || choice != 3 || choice != 4)
{
printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\nChoice: ");
scanf("%d", &choix);
if (choice > 4)
{
prinf("Invalid choice\n");
}
if (choice == 0)
{
printf ("Bye!\n");
return (0);
}
if (choice == 1)
{
addition();
}
if (choice == 2)
{
subtraction();
}
if (choice == 3)
{
multiplication();
}
if (choice == 4)
{
division();
}
}
return(0);
}
