#include <stdio.h>

/**
 * main - prints all the numbers of base 16 in lowercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int chiffre = '0';
int lettre = 'a';
while (chiffre <= '9')
{
putchar(chiffre);
chiffre++;
}
while (lettre <= 'f')
{
putchar(lettre);
lettre++;
}
putchar('\n');

return (0);
}
