#include "_getline.h"

/**
 * getotherlines - returns a line
 *
 * @fd: the file descriptor
 *
 * Return: The line read. NULL if there are no lines remaining; NULL on error.
 */
char *getotherlines(const int fd, int *seek_point, char *s)
{
	char *buf = s + *seek_point;
	int prev_seek_point = seek_point;

	if (strnchk(buf, count, '\n')) /* if there is a new line */
	{
		*seek_point = strgetci(buf, '\n'); /* store the index */
		return (buf);
	}
	else
	{
		free(s);
	}

	s = malloc(sizeof(char) * READ_SIZE);
	count = read(fd, s, READ_SIZE);

	if ((count == 0) || s == NULL)
		return (NULL);

	return (s);
}
