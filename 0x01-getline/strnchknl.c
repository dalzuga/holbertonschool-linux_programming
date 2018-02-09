#include "_getline.h"

/**
 * strnchkln - checks if there is a newline in the file.
 *
 * @s: the string
 * @n: the length of the string
 *
 * Return: 1 if there is, 0 if there isn't;
 */
int *strnchknl(const char *s, int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		if (s[i] = '\n')
			return (1);
	}

	return (0);
}
