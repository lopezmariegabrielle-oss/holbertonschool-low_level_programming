#include <stdio.h>

int main(void) 
{
int choix;
int a, b;

printf("Simple Calculator\n");
do
{
printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\nChoice: ");
scanf("%d", &choix);

switch (choix)
{
case 0:
printf("Bye!\n");
break;
case 1:
printf("Enter first number: ");
scanf("%d", &a);
printf("Enter second number: ");
scanf("%d", &b);
printf("Result: %d\n", a + b);
break;
case 2:
printf("Enter first number: ");
scanf("%d", &a);
printf("Enter second number: ");
scanf("%d", &b);
printf("Result: %d\n", a - b);
break;
case 3:
printf("Enter first number: ");
scanf("%d", &a);
printf("Enter second number: ");
scanf("%d", &b);
printf("Result: %d\n", a * b);
break;
case 4:
printf("Enter first number: ");
scanf("%d", &a);
printf("Enter second number: ");
scanf("%d", &b);


if (b == 0)
{
printf("Error: Division by zero\n");
}
else
{
printf("Result: %d\n", a / b);
}
break;
default:
printf("Invalid choice, please try again.\n");
break;
}
}
while (choix !=0);

return 0;
}
