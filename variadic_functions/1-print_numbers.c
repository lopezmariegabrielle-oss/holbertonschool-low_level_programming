#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_numbers - prints numbers, followed by a new line
 * @separator: the string to be printed between numbers
 * @n: the number of integers passed to the function
 * @...: the integers to be printed
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
va_list ap;
unsigned int i;

va_start(ap, n);

i = 0;
while (i < n)
{

int current_number = va_arg(ap, int);

printf("%d", current_number);

if (separator != NULL && i < n - 1)
{
printf("%s", separator);
}
i++;
}
printf("\n");
va_end(ap);
}
