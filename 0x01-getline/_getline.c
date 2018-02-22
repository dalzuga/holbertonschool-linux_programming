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
	static char *s = NULL, *ts = NULL;
	char *line = NULL;
	static int s_count, si, ts_count, tsi;
	char *s2 = NULL;
	int s2_count = 0;
	int total;

	if (si == -1)		/* if we're done */
		return (NULL);

	/* ts might contain '\n' */
	if (strnchkc(ts, ts_count, '\n')) /* check for '\n' in ts */
	{
		tsi = strgetci(ts, '\n');
		line = malloc(sizeof(char) * tsi);
		strncpy(line, ts, tsi);
		line[tsi - 1] = '\0';
		ts_count = ts_count - tsi;
		ts = ts + tsi;	/* advance ts pointer */
		return (line);
	}

	/* ts does not contain '\n' */
	if (strnchkc(s, s_count, '\n')) /* check for '\n' in s */
	{
		si = strgetci(s, '\n'); /* get the index of '\n' */
		line = malloc(sizeof(char) * (ts_count + si));
		strncpy(line, ts, ts_count);
		strncpy(line + ts_count, s, si - s);

		line[ - 1] = '\0';

		free(ts);
		ts_count = s_count - si;
		ts = malloc(sizeof(char) * ts_count);
		strncpy(ts, s, ts_count);
		free(s);
		return (line);
	}
	else			/* if we need more characters in s */
	{
		while (strnchkc(s2, s2_count, '\n' == 0))
		{
			s2 = malloc(sizeof(char) * (s_count + READ_SIZE));
			s2_count = read(fd, s2 + s_count, READ_SIZE);
			if (s2_count == 0) /* we're done */
			{
				line = malloc(sizeof(char) * (ts_count + s_count + 1));
				strncat(line, ts_count, ts);
				strncat(line + ts_count, s_count, s);
				line[ts_count + s_count] = '\0';

				si = -1; /* signal that we're done */
				return (line);
			}
		}
	}
}
