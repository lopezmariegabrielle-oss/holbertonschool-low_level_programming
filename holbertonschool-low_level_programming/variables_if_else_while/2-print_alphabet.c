#include <stdio.h>
/**
* main - prints the alphabet in lowercase
*
* Return: 0;
*/
int main(void)
{
	char lettre;

	for (lettre = 'a' ; lettre <= 'z'; lettre++)
	{
		putchar(lettre);
	}
	putchar('\n');
	return (0);
}
