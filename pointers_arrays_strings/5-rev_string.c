#include "main.h"

/**
 * rev_string - inverse une chaîne de caractères en mémoire
 * @s: la chaîne à inverser
 */
void rev_string(char *s)
{
int len = 0;
int i = 0;
char temp;

	if (s == NULL)
	{
		return;
	}
while (s[len] != '\0')
{
len++;
}
for (i = 0; i < len / 2; i++)
{
temp = s[i];
s[i] = s[len - 1 - i];
s[len - 1 - i] = temp;
}
}
