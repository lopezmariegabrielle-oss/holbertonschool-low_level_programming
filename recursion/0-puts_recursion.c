#include "main.h"

/**
 * _puts_recursion - prints a string, followed by a new line
 * @s: the string to print
 *
 * Return: void
 */
void _puts_recursion(char *s)
{
if (*s != '\0')
{
_putchar(*s); /* si le caractére actuel est pas la fin */
_puts_recursion(s + 1); /* passe au suivant */
}
else
{
_putchar('\n');
}
}
