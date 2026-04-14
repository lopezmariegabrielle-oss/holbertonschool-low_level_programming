#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * p_char - Imprime un caractère
 * @ap: Liste d'arguments
 */
void p_char(va_list ap)
{
printf("%c", va_arg(ap, int));
}
/**
 * p_int - Imprime un entier
 * @ap: Liste d'arguments
 */
void p_int(va_list ap)
{
printf("%d", va_arg(ap, int));
}
/**
 * p_float - Imprime un nombre à virgule
 * @ap: Liste d'arguments
 */
void p_float(va_list ap)
{
printf("%f", va_arg(ap, double));
}
/**
 * p_string - Imprime une chaîne (gère le cas NULL)
 * @ap: Liste d'arguments
 */
void p_string(va_list ap)
{
char *s = va_arg(ap, char *);

if (s == NULL)
{
printf("(nil)");
return;
}
printf("%s", s);
}
/**
 * print_all - Imprime n'importe quoi selon le format fourni
 * @format: Liste des types d'arguments (c, i, f, s)
 */
void print_all(const char * const format, ...)
{
va_list ap;
int i = 0, j;
char *sep = "";
f_t types[] = {
{'c', p_char},
{'i', p_int},
{'f', p_float},
{'s', p_string},
{'\0', NULL}
};

va_start(ap, format);

/* On vérifie si format existe ET n'est pas vide */
while (format && format[i])
{
j = 0;
/* Correction : On vérifie explicitement types[j].id */
while (types[j].id != '\0')
{
/* On compare le caractère du format avec l'id du tableau */
if (format[i] == types[j].id)
{
printf("%s", sep);
types[j].f(ap);
sep = ", ";
break;
}
j++;
}
i++;
}
va_end(ap);
printf("\n");
}
