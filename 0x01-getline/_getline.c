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
	char *s = NULL;
	static int seek_point;
	char *line = NULL;
	int count = 0, ts_count = 0;

	/* seek_point is just the first '\n' */
	s = getfirstline(fd, &seek_point, &count);

	printf("_getline: %s", s);
	printf("seek_point: %d\n", seek_point);

	line = malloc(sizeof(char) * (ts_count + seek_point));

	strncpy(line, s, seek_point);

	while (1)
	{
		line = getinsidelines(&seek_point, s, &count);
		if (line == NULL) /* broke cleanly */
			break;
		printf("%s", line);
	}

	/* broke messily, there are trailing chars from next line */

	return (NULL);
}
