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
	char *buf = s + *seek_point, *s2 = NULL;
	int prev_seek_point = *seek_point, buf_count = 0;

	/*
         * while (buf == '\n')
	 * {
	 * 	buf++;
	 * 	(*seek_point)++;
	 * }
         */

	if (strnchkc(buf, *count, '\n')) /* if there is a new line */
	{
		*seek_point = strgetci(buf, '\n'); /* store the index */
		*count = *seek_point - prev_seek_point;
		return (buf);
	}
	else if (buf != NULL)
	{
		buf_count = count - seek_point; /* calculate trail length */
		s2 = malloc(sizeof(char) * (buf_count + READ_SIZE));
		strncpy(s2, buf, buf_count);
	}
	else
	{
		return (NULL);
	}
}
