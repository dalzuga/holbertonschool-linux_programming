#include "_getline.h"

/**
 * getinsidelines - returns a line
 *
 * @fd: the file descriptor
 *
 * Return: The line read. NULL if there are no lines remaining; NULL on error.
 */
char *getinsidelines(int *seek_point, char *s, int *count)
{
	char *buf = s + *seek_point;
	int prev_seek_point = *seek_point;

	if (strnchkc(buf, *count, '\n')) /* if there is a new line */
	{
		*seek_point = strgetci(buf, '\n'); /* store the index */
		*count = *seek_point - prev_seek_point;
		return (buf);
	}
	else if (buf != NULL)
	{
		return (s);
	}
	else
	{
		return (NULL);
	}

	/* 
         * s = malloc(sizeof(char) * READ_SIZE);
	 * *count = read(fd, s, READ_SIZE);
	 * 
	 * if ((*count == 0) || s == NULL)
	 * 	return (NULL);
	 * 
	 * return (s);
         */
}
