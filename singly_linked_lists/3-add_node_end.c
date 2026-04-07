#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: double pointer to the list_t list
 * @str: string to be put in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *last;
	unsigned int i = 0;

	if (str == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
		if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	while (str[i])
		i++;
	new->len = i;
	new->next = NULL;
/*Si la liste et vide le nouveau devien premier */
	if (*head == NULL)
{
	*head = new;
	return (new);
}
/*Sinon on cherche le dernier wagon actuel */
last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	/*Accroche le nouveau wagon a la fin */
	last->next = new;
	return (new);
}
