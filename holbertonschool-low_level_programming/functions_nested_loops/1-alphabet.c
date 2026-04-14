#include <stdio.h>
#include "main.h"
/**
* print_alphabet - affiche l'alphabet en minuscules
*/
void print_alphabet(void)
{
char lettre = 'a';
while (lettre <= 'z')
{
_putchar(lettre);
lettre++;
}
_putchar('\n');

return;
}
