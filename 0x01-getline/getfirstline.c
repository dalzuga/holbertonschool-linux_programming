#include "_getline.h"

/**
 * getfirstline - reads a string with at least one line from a file
 *
 * @fd: the file descriptor
 *
 * Return: The line read. NULL if there are no lines remaining; NULL on error.
 */
char *getfirstline(const int fd)
{
	int count = 0, s2_count = 0, i = 0;
	char *s = NULL, *s2 = NULL;

	s = malloc(sizeof(char) * BUFFER_SIZE);
	count = read(fd, s, BUFFER_SIZE);

	if ((count == 0) || s == NULL)
		return (NULL);

	for (i = 1; ; i++)
	{
		if (strnchknl(s, count)) /* if there is a new line */
		{
			seek_point = strgetci(); /* store the index */
			break;
		}
		else		/* read more characters from the file into s */
		{
			/* make bigger chunk of memory in variable s2 */
			s2 = malloc(sizeof(char) * (count + BUFFER_SIZE));
			/* copy s into s2 */
			strncat(s2, s, count);
			/* read more into s2 */
			s2_count = read(fd, s + count, BUFFER_SIZE);
			free(s);
			/* remake s with size `count + s2_count` */
			s = malloc(sizeof(char) count + s2_count);
			strncat(s, s2, count + s2_count);
			/* update count */
			count += s2_count;
		}
	}

	
}
