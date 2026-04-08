#include <stdio.h>
#include "binary_trees.h"

/* Fonction utilitaire pour l'affichage */
void binary_tree_print(const binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	/* Version simplifiée pour visualiser la structure */
	printf("(%03d)", tree->n);
	if (tree->left || tree->right)
	{
		printf(" L:");
		if (tree->left) binary_tree_print(tree->left); else printf("NULL");
		printf(" R:");
		if (tree->right) binary_tree_print(tree->right); else printf("NULL");
	}
}
