#include "main.h"

/**
 * puts2 - prints every other character of a string
 * @str: the string to be treated
 */
void puts2(char *str)
{
	int i = 0;

	/*
	 * On verifie si le pointeur est NULL.
	 */
	if (str == NULL)
	{
		return;
	}

	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			_putchar(str[i]);
		}
		i++;
	}
	_putchar('\n');

}
