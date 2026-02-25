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
    r = _islower('a'); /* Devrait renvoyer 1 */
    _putchar(r + '0');
    r = _islower('A'); /* Devrait renvoyer 0 */
    _putchar(r + '0');
    r = _islower('z'); /* Devrait renvoyer 1 */
    _putchar(r + '0');
    _putchar('\n');
    return (0);

return (0);
}
