#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: 2D array of chars
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
int i = 0;
int j;

if (a == NULL)
return;

while (i < 8)
{
j = 0;
while (j < 8)
{
_putchar(a[i][j]);
j++;
}
_putchar('\n');
i++;
}
}
