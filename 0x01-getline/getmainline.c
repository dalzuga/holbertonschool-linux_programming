#include "_getline.h"

/**
 * getmainline - reads a string with at least one line from a file
 *
 * @fd: the file descriptor
 *
 * Return: The line read. NULL if there are no lines remaining; NULL on error.
 */
char *getmainline(const int fd, int *seek_point, int *count)
{
	int s2_count = 0, i = 0;
	char *s = NULL, *s2 = NULL;

	s = malloc(sizeof(char) * READ_SIZE);
	*count = read(fd, s, READ_SIZE);

	if ((*count == 0) || s == NULL)
		return (NULL);

	for (i = 1; ; i++)
	{
		if (strnchkc(s, *count, '\n')) /* if there is a new line */
		{
			*seek_point = strgetci(s, '\n'); /* store the index */
			break;
		}
		else		/* read more characters from the file into s */
		{
			/* make bigger chunk of memory in variable s2 */
			s2 = malloc(sizeof(char) * (*count + READ_SIZE));
			/* copy s into s2 */
			strncat(s2, s, *count);
			/* read more into s2 */
			s2_count = read(fd, s2 + *count, READ_SIZE);
			free(s);
			/* remake s with size `*count + s2_count` */
			s = malloc(sizeof(char) * (*count + s2_count));
			strncat(s, s2, *count + s2_count);
			/* update *count */
			*count += s2_count;
		}
	}

	return (s);
}
