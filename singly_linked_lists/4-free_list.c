#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the start of the list
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		/*Je garde l'adreese du prochain pour ne pas le perdre */
		temp = head->next;

		/* Je libere le contenu du wagon actuel */
		free(head->str);

		/*je libere le wagon lui-meme */
		free(head);

		/*J'avence le wagon suivant que j'ai mis de côté */
		head = temp;
	}
}
