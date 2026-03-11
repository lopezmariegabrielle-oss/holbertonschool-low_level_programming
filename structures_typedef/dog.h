#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Une structure regroupant les infos d'un chien
 * @name: Premier membre (nom du chien)
 * @age: Deuxième membre (âge du chien)
 * @owner: Troisième membre (nom du propriétaire)
 */
typedef struct dog
{
char *name;
float age;
char *owner;
} dog_t;
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);

#endif /* DOG_H */
