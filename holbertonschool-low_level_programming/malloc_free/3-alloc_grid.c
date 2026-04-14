#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - creates a 2D array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to 2D array, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
int **grid;
int i, j;
if (width <= 0 || height <= 0)
return (NULL);
/* Alloue un tableau de pointeurs pour les lignes de la grille */
grid = malloc(sizeof(int *) * height);
/*
*Vérifie si l'allocation du tableau de
*lignes a réussi avant de continuer
*/
if (grid == NULL)
return (NULL);
/* Boucle principale pour créér chaque ligne */
i = 0;
while (i < height)
{
grid[i] = malloc(sizeof(int) * width);
/*si cette allocation échou je nettoir tout*/
if (grid[i] == NULL)
{
while (i > 0)
{
i--;
free(grid[i]);
}
free(grid);
return (NULL);
}
/*si l'allocation réussi je remplit la ligne de zéros*/
j = 0;
while (j < width)
{
grid[i][j] = 0;
j++;
}
i++;
}
return (grid);
}
