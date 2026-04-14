#include <stdio.h>
/**
 * main - prints all single digit numbers of base 10 starting from 0
 *
 * Return: 0;
 */
int main(void)
{
int n = 'z';

while (n >= 'a')
{
putchar(n);
n--;
}
putchar('\n');

return (0);
}
