#include "_getline.h"

/**
 * _getline - reads a line from a file
 *
 * @fd: the file descriptor
 *
 * Return: The line read. NULL if there are no lines remaining; NULL on error.
 */
char *_getline(const int fd)
{
	char *buffer;
	int count;

	count = read(fd, buffer, READ_SIZE);
}
