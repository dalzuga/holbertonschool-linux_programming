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
	char *buf = NULL, *s = NULL;
	int count = 1;
	int i = 0;
	int nl_flag = 0;

	count = 1;

	while (count != -1)
	{
		count = read(fd, buf, READ_SIZE);
		for (i = 0; i < count; i++)
		{
			if (buf[i] == '\n')
			{
				nl_flag = 1;
				break;
			}
		}
	}

	if (nl_flag == 1)
	{
		s = malloc(sizeof(char) * i);
		if (s == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		strncpy(s, buf, i);
		s[i] = '\0';
	}

	return (s);
}

