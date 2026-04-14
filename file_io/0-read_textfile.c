#include "main.h"

/**
 * read_textfile - lit un fichier texte et l'affiche sur la sortie standard.
 * @filename: nom du fichier à lire.
 * @letters: nombre de lettres à lire et à afficher.
 *
 * Return: le nombre réel de lettres lues et affichées. 0 si erreur.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t n_read, n_wrote;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}
	n_read = read(fd, buffer, letters);
	/*Vérification si read a fonctionné*/
	if (n_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	n_wrote = write(STDOUT_FILENO, buffer, n_read);
	/*Vérication si write a fonctionné et tout écrit*/
	if (n_wrote == -1 || n_wrote != n_read)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	free(buffer);
	close(fd);
	return (n_read);
}
