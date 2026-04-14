#include <stdio.h>
#include "main.h"
/**
* print_alphabet_x10 - affiche 10 fois l'alphabet
*/
void print_alphabet_x10(void)
{
int i;
char lettre;
for (i = 0; i < 10; i++)
{
lettre = 'a';
while (lettre <= 'z')
{
_putchar(lettre);
lettre++;
}
_putchar('\n');
}
return;
}
