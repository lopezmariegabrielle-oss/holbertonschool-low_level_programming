#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: string to be treated
 */

void puts_half(char *str)
{
int len = 0;
int i, start;
if (str == NULL)
{
return;
}
while (str[len] != '\0')
len++;

start = (len + 1) / 2;

i = start;
while (i < len)
{
_putchar(str[i]);
i++;
}
_putchar('\n');
}
