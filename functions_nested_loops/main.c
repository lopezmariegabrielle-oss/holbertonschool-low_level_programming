#include "main.h"
/**
* main - check the code
*
* Return: Always 0.
*/
int main(void)
{
int r;
/*execice 1*/
print_alphabet();
/*exercice 2*/
print_alphabet_x10();
/*exercice 3*/
    r = _islower('a');
    _putchar(r + '0');
    r = _islower('A');
    _putchar(r + '0');
    r = _islower('z');
    _putchar(r + '0');
    _putchar('\n');
  
/*exercice 4*/
r = _isalpha('H'); 
    _putchar(r + '0');
    r = _isalpha('o'); 
    _putchar(r + '0');
    r = _isalpha(';'); 
    _putchar(r + '0');
    _putchar('\n');

return (0);
}
