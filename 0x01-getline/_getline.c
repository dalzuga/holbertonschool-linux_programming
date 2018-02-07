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
	static int seek_point, seek_offset;
	static char *buf = NULL;
	int i = 0, j = 0, s_count = 0, flag = 0;
	char *s = NULL;

	/* i must start at seek_point + seek_offset */
	for (i = 0; ; i++)
	{
		if (buf != NULL) /*
				  * this means:
				  * a) this is not the first iteration, and,
				  * b) we have picked up some characters in the
				  * line after the previous iteration
				  * c) if (b), then these characters are at buf
				  */
		{
			i = seek_point + seek_offset;
		}

		if (i == 0)
		{
			s = malloc(sizeof(char) * READ_SIZE);
			s_count = read(fd, s, READ_SIZE);
		}
		if (s_count == 0) /* we've read the entire line */
			break;
		if (s[i] == '\n') /* if end of line, but not end of buffer */
		{
			seek_point = i;
			seek_offset = s_count - i;
			flag = 1;
		}

		/* we've picked up some of the next line */
		if (flag && (seek_offset >= 0))
		{
			buf = malloc(sizeof(char) seek_offset);

			/* probably an "off by one" error here */
			strncat(buf, s[i+1], seek_offset);
		}
		else 		/*
				 * (seek_offset must be 0) => (we haven't
				 * picked up characters from the rest of the
				 * line)
				 */
		{
			break;	/* this is the end of the line */
		}
	}

	/*
         * s1 = "hello";
	 * s2 = "hi";
	 * s3 = malloc(sizeof(char) * (strlen(s1) + strlen(s2)));
	 * strcat(s3, s1);
	 * strcat(s3, s2);
	 *
	 * printf("%s\n", s3);
         */

	/* 
         * char *s __attribute__((unused)) = NULL;
	 * char *s2 __attribute__((unused)) = NULL;
	 * char *buf = NULL;
	 * int s_len __attribute__((unused)) = 0;
	 * int s2_count __attribute__ ((unused)) = 0;
	 * int buf_len __attribute__((unused)) = 0;
	 * int i = 0;
	 * int count = 0;
	 * 
	 * while (1)
	 * {
	 * 	buf = malloc(sizeof(char) * READ_SIZE);
	 * 	count = read(fd, buf, READ_SIZE);
	 * 
	 * 	if (count == 0) /\* end of file *\/
	 * 		break;
	 * 
	 * 	for (i = 0; buf[i] != '\n'; i++) /\* look for new line *\/
	 * 	{
	 * 		/\* Appends: s = buf + s2; buf = s. *\/
	 * 		if (i >= READ_SIZE) /\* if no new line (line is long) *\/
	 * 		{
	 * 			s2 = malloc(sizeof(char) * READ_SIZE);
	 * 			s2_count = read(fd, s2, READ_SIZE); /\* read *\/
	 * 			s = malloc(sizeof(char) * (count + s2_count));
	 * 			s = strcat(buf, s2);
	 * 			buf = s;
	 * 			count = strlen(buf);
	 * 		}
	 * 	}
	 * }
	 * 
	 * printf("--------at newline------------:\n%s", buf);
         */

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
