#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - initialise une variable de type struct dog
 * @d: pointeur vers la struct dog à initialiser
 * @name: nom à donner au chien
 * @age: âge à donner au chien
 * @owner: nom du propriétaire
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d != NULL)
{
d->name = name;
d->age = age;
d->owner = owner;
}
}
