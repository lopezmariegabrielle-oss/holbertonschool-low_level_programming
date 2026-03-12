#include "dog.h"
#include <stdlib.h>
/**
 * free_dog - libère la mémoire allouée pour un chien
 * @d: pointeur vers la structure du chien à libérer
 */
void free_dog(dog_t *d)
{
if (d != NULL)
{
/*Libere les chene allouées a l'interrieur*/
free(d->name);
free(d->owner);
/*Libere le structure elle-même*/
free(d);
}
}
