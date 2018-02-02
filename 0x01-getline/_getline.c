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
	int index;
	char *s = NULL, *s2 __attribute__((unused)) = NULL;
	char *buf = NULL;
	int i = 0;
	int count = 0;
	int multiplier = 1;

	while (1)
	{
		buf = malloc(sizeof(char) * READ_SIZE);
		count = read(fd, buf, READ_SIZE);

		if (count == 0) /* end of file */
			break;

		for (i = 0; buf[i] != '\n'; i++)
		{
			if (i >= READ_SIZE)
			{
				/* alloc more */
			}
		}

		s = malloc(sizeof(count));
		strncpy(s, buf, count);

		/* 
                 * for (i = 0; i < READ_SIZE; i++)
		 * {
		 * 	if (buf[i] == '\n') /\* go until you find a newline *\/
		 * 	{
		 * 		s = malloc(sizeof(char) * i);
		 * 		multiplier = i/64;
		 * 		s2 = malloc(sizeof(char) * READ_SIZE * multiplier);
		 * 		strncpy(s, buf, i);
		 * 		buf[i] = '\0'; /\* replace new line *\/
		 * 		s[i] = '\0'; /\* replace new line *\/
		 * 		return (s);
		 * 	}
		 * }
                 */
	}

	printf("--------at newline------------:\n%s\n", buf);

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
