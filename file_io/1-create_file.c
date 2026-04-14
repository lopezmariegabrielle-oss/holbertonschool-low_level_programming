#include "main.h"

int create_file(const char *filename, char *text_content)
{
    int fd;
    int i = 0;
    ssize_t n_wrote;

    if (filename == NULL)
        return (-1);

    /*Ouverture de fichier avec les permissions*/
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

    if (text_content[i] != '\0')
    {
        while (text_content[i] != '\0')
        {
            i++;
        }
    }
    n_wrote = write(fd, text_content, i);
    if (n_wrote == -1 || n_wrote != i)
    {
        close(fd);
        return (-1);
    }
    close(fd);
    return (1);
}
