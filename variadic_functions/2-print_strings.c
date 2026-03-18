#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_strings - prints strings, followed by a new line
 * @separator: the string to be printed between the strings
 * @n: the number of strings passed to the function
 * @...: the strings to be printed
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
va_list ap;
unsigned int i;
char *str;

va_start(ap, n);
i = 0;
while (i < n)
{
str = va_arg(ap, char *);

if (str != NULL)
{
printf("%s", str);
}
else
{
printf("(nil)");
}
if (separator != NULL && i < n - 1)
{
printf("%s", separator);
}

i++;
}
printf("\n");
va_end(ap);
}
