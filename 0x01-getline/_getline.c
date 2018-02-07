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
	char *s __attribute__((unused)) = NULL;
	char *s2 __attribute__((unused)) = NULL;
	char *buf = NULL;
	int s_len __attribute__((unused)) = 0;
	int s2_count __attribute__ ((unused)) = 0;
	int buf_len __attribute__((unused)) = 0;
	int i = 0;
	int count = 0;

	while (1)
	{
		buf = malloc(sizeof(char) * READ_SIZE);
		count = read(fd, buf, READ_SIZE);

		if (count == 0) /* end of file */
			break;

		for (i = 0; buf[i] != '\n'; i++) /* look for new line */
		{
			/* Appends: s = buf + s2; buf = s. */
			if (i >= READ_SIZE) /* if no new line (line is long) */
			{
				s2 = malloc(sizeof(char) * READ_SIZE);
				s2_count = read(fd, s2, READ_SIZE); /* read */
				s = malloc(sizeof(char) * (count + s2_count));
				s = strcat(buf, s2);
				buf = s;
				count = strlen(buf);
			}
		}
	}

	printf("--------at newline------------:\n%s", buf);

	return (NULL);
}

/**
 * _getfirstline - reads a line from a file
 *
 * @fd: the file descriptor
 *
 * Return: The line read. NULL if there are no lines remaining; NULL on error.
 */
char *_getfirstline(const int fd)
{
	char *buf = NULL, *s = NULL;
	int count = 1;
	static int i;
	int nl_flag = 0;

	count = 1;

	buf = malloc(sizeof(char) * READ_SIZE);
	if (buf == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	while ((count != -1) && (count != 0) && (nl_flag == 0))
	{
		count = read(fd, buf, READ_SIZE);
		for (; i < count - 1; i++)
		{
			if (buf[i] == '\n')
			{
				nl_flag = 1;
				break;
			}
		}
	}

	s = malloc(sizeof(char) * (i + 1));
	if (s == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	strncpy(s, buf, i);
	s[i + 1] = '\0';

	free(buf);

	if (count == 0)
	{
		free(s);
		return (NULL);
	}

	return (s);
}
