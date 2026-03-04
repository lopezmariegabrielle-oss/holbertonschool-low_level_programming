#include "main.h"

/**
 * puts2 - affiche un caractère sur deux d'une chaîne
 * @str: la phrase qu'on me donne à traiter
 */
void puts2(char *str)
{
	int i = 0;
/*Je parcours la phrase en affichant une lettre, 
* puis je saute la suivante (+2). Si je dépasse la fin, 
* je m'arrête pour ne pas lire de bêtises en mémoire.
*/
	while (str[i] != '\0')
	{
		_putchar(str[i]);

	    i = i + 2;
	
        if (str[i - 1] == '\0')
		{
			break;
		}
	}
	_putchar('\n');
}