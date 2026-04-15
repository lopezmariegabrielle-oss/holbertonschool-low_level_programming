#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * close_file - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to close.
 */

void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments.
 * @argv: array of arguments.
 *
 * Return: 0 on success, or exit codes 97-100 on failure.
 */

int main(int argc, char **argv)
{
	int fd_from, fd_to;
	ssize_t n_read, n_wrote;
	char buffer[1024];

	if  (argc != 3)/*Vérification si j'ai bien 3 arguments*/
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	} /*Ouverture de la source*/
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		exit(99);
	} /*Boucle de lecture et d'écriture*/
	while ((n_read = read(fd_from, buffer, 1024)) > 0)
	{
		n_wrote = write(fd_to, buffer, n_read);
		if (n_wrote == -1 || n_wrote != n_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}
	if (n_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close_file(fd_from), close_file(fd_to), exit(98);
	}
	close_file(fd_from), close_file(fd_to);
	return (0);
}
