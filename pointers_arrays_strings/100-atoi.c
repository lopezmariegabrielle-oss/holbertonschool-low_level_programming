#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the integer converted from the string
 */
int _atoi(char *s)
{
	int i = 0;
	int res = 0;
	int sig = 1;
	int found = 0;

	if (s == NULL)
		return (0);

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sig *= -1;
		}

		if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;

			res = (res * 10) + (s[i] - '0') * sig;

			if (s[i + 1] < '0' || s[i + 1] > '9')
			{
				break;
			}
		}
		i++;
	}

	if (found == 0)
		return (0);

	return (res);
}
