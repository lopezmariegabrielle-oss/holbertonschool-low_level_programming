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

/* exercice 5*/
    r = print_sign(98);  
    _putchar(',');
    _putchar(' ');
    _putchar(r + '0');
    _putchar('\n');

    r = print_sign(0);    
    _putchar(',');
    _putchar(' ');
    _putchar(r + '0');
    _putchar('\n');

    r = print_sign(-5);   
    _putchar(' ');
    _putchar('\n');
    
/* exercice 6 */
    r = _abs(-1);
    _putchar(r + '0'); 
    _putchar('\n');

    r = _abs(0);
    _putchar(r + '0');
    _putchar('\n');

    r = _abs(98);
    _putchar('\n');

/*exercice 7*/
print_last_digit(98);
    print_last_digit(0);
    r = print_last_digit(-1024);
    _putchar('0' + r);
    _putchar('\n');

/*exercice 8*/
_putchar('\n');
jack_bauer();

/*exercice 9*/
times_table();

return (0);
}
