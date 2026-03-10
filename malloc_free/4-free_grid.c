#include "main.h"
#include <stdlib.h>
/**
 * free_grid - frees a 2D grid previously created by alloc_grid
 * @grid: 2D grid to be freed
 * @height: height of the grid
 *
 * Return: nothing
 */
void free_grid(int **grid, int height)
{
int i = 0;
/*Boucle pour liberer chaque ligne une par une*/
while (i < height)
{
free(grid[i]);
i++;
}
/*libere le tableau de pointeur principal*/
free(grid);
}
