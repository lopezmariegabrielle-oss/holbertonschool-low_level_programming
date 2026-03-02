#include <stdio.h>

/**
 * main - Affiche un menu de calculatrice et gère la sortie
 *
 * Return: Toujours 0 (Succès)
 */
void addition(void);
void subtraction(void);
void multiplication(void);
void division(void);
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

} while (choice != 0);

return (0);

}
/**
 * addition - Adds two integers and prints the result
 *
 * Return: void
 */
void addition(void)
{
int a, b;

printf("A: ");
scanf("%d", &a);
printf("B: ");
scanf("%d", &b);
printf("Result: %d\n", a + b);
}

/**
 * subtraction - Subtracts two integers and prints the result
 *
 * Return: void
 */
void subtraction(void)
{
int a, b;

printf("A: ");
scanf("%d", &a);
printf("B: ");
scanf("%d", &b);
printf("Result: %d\n", a - b);
}

/**
 * multiplication - Multiplies two integers and prints the result
 *
 * Return: void
 */
void multiplication(void)
{
int a, b;

printf("A: ");
scanf("%d", &a);
printf("B: ");
scanf("%d", &b);
printf("Result: %d\n", a * b);
}

/**
 * division - Divides two numbers with zero-check
 *
 * Return: void
 */
void division(void)
{
float a, b;

printf("A: ");
scanf("%f", &a);
printf("B: ");
scanf("%f", &b);

if (b == 0)
{
printf("Error: division by zero\n");
}
else
{
printf("Result: %.1f\n", a / b);
}
}
