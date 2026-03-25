#include "dog.h"
#include <stdlib.h>
/**
 * _strlen - calcule la longueur d'une chaîne
 * @s: la chaîne à mesurer
 * Return: la longueur
 */
int _strlen(char *s)
{
int len = 0;

while (s[len])
len++;
return (len);
}
/**
 * _strcpy - copie une chaîne vers une autre
 * @dest: destination
 * @src: source
 * Return: le pointeur vers dest
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}
/**
 * new_dog - crée un nouveau chien
 * @name: nom du chien
 * @age: âge du chien
 * @owner: propriétaire du chien
 * Return: pointeur vers le nouveau chien, ou NULL si échec
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *d;
int len_n, len_o;
if (name == NULL || owner == NULL)
return (NULL);
/*Mesure des longeures*/
len_n = _strlen(name);
len_o = _strlen(owner);
/*Allocation structure procipal*/
d = malloc(sizeof(dog_t));
if (d == NULL)
return (NULL);
/*Allocation et copie du Nom*/
d->name = malloc(sizeof(char) * (len_n + 1));
if (d->name == NULL)
{
free(d); /* Si le nom rate, on libère d */
return (NULL);
}
_strcpy(d->name, name);

/*Allocation et copie du Proprietaire*/
d->owner = malloc(sizeof(char) * (len_o + 1));
if (d->owner == NULL)
{
/*Libère tout ce qui a été fait avant !*/
free(d->name);
free(d);
return (NULL);
}
_strcpy(d->owner, owner);
/*Donne l'âge et renvoie le pointeur*/
d->age = age;
return (d);
}
