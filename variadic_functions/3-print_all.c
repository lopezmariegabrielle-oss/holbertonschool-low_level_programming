#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * @...: arguments to be printed
 */
void print_all(const char * const format, ...)
{
va_list ap;
unsigned int i = 0;
char *str;
char *sep = ""; /* vide au bébut */
va_start(ap, format);
while (format && format[i])
{
if (format[i] == 'c' || format[i] == 'i' ||
format[i] == 'f' || format[i] == 's')
{
switch (format[i]) /* pour regarder le caractere actuel */
{
case 'c':
printf("%s%c", sep, va_arg(ap, int));
break;
case 'i':
printf("%s%d", sep, va_arg(ap, int));
break;
case 'f':
printf("%s%f", sep, va_arg(ap, double));
break;
case 's':
str = va_arg(ap, char *);
if (str == NULL)
{
str = "(nil)";
}
printf("%s%s", sep, str);
break;
default:
i++;
continue; /* saute le changement de  'sep si c'est pas un bon type */
}
sep = ","; /* apres le 1er passage sep devient "," */
}
i++;
}
printf("\n");
va_end(ap);
}
