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
	static int seek_point;
	char *line = NULL;
	int count = 0;

	s = getmainline(fd, &seek_point, &count);

	printf("_getline: %s", s);
	printf("seek_point: %d\n", seek_point);

	line = malloc(sizeof(char) * seek_point);
	strncpy(line, s, seek_point);

	while (1)
	{
		line = getinsidelines(fd, &seek_point, s, &count);
		if (line == NULL)
			break;
		printf("%s", line);
	}

	return (NULL);
}
