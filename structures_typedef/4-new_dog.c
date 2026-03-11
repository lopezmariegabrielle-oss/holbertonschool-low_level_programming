#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - crée un nouveau chien (avec copie des données)
 * @name: nom du chien
 * @age: âge du chien
 * @owner: propriétaire du chien
 * Return: pointeur vers le nouveau chien, ou NULL si échec
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *d;
int len_name = 0, len_owner = 0;
int i;

/*Mesure des longeures*/
while (name[len_name])
len_name++;
while (owner[len_owner])
len_owner++;
/*Allocation structure procipal*/
d = malloc(sizeof(dog_t));
if (d == NULL)
return (NULL);
/*Allocation et copie du Nom*/
d->name = malloc(sizeof(char) * (len_name + 1));
if (d->name == NULL)
{
free(d); /* Si le nom rate, on libère d */
return (NULL);
}
i = 0;
while (name[i] != '\0')
{
d->name[i] = name[i];
i++;
}
d->name[i] = '\0';
/*Allocation et copie du Proprietaire*/
d->owner = malloc(sizeof(char) * (len_owner + 1));
if (d->owner == NULL)
{
/*Libère tout ce qui a été fait avant !*/
free(d->name);
free(d);
return (NULL);
}
i = 0;
while (owner[i])
{
d->owner[i] = owner[i];
i++;
}
d->owner[i] = '\0';

/*Donne l'âge et renvoie le pointeur */
d->age = age;

return (d);
}
