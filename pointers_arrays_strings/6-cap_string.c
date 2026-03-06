#include "main.h"

/**
 * cap_string - Capitalise tous les mots d'une chaîne.
 * @str: La chaîne à modifier.
 *
 * Return: Un pointeur vers la chaîne modifiée.
 */
char *cap_string(char *str)
{
int i = 0;
int j;
char sep[] = " \t\n,;.!?\"(){}";

if (str == NULL)
return (NULL);

/*vérification de la toute premiere lettre*/
if (str[i] >= 'a' && str[i] <= 'z')
{
str[i] = str[i] - 32;
}
while (str[i] != '\0')
{
j = 0;

/*Boucle pour testé si str[i] est un séparatuer*/
while (sep[j] != '\0')
{
if (str[i] == sep[j])

/*condition de transformation*/
{
if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
{
str[i + 1] -= 32;
}
}
j++;
}
i++;
}
return (str);
}
