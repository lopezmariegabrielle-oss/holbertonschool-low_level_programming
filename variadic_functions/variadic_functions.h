#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>

/**
 * struct format_types - Structure pour associer un format à une fonction
 * @id: Le caractère du format (c, i, f, s)
 * @f: Le pointeur vers la fonction d'impression correspondante
 */
typedef struct format_types
{
char id;
void (*f)(va_list);
} f_t;

/* Prototypes des fonctions */
int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
