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
	/* trying something different */
	char *s __attribute__((unused)) = NULL;
	static char *line;

	s = getfirstline(fd);

	printf("_getline: %s", s);
	printf("end\n");

	return (NULL);
}
