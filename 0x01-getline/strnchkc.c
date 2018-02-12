#include "_getline.h"

/**
 * strnchkc - checks if there is a character 'c' in the file.
 *
 * @s: the string
 * @n: the length of the string
 * @c: the character
 *
 * Return: 1 if there is, 0 if there isn't.
 */
int strnchkc(const char *s, int n, char c)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		if (s[i] == c)
			return (1);
	}

	return (0);
}
