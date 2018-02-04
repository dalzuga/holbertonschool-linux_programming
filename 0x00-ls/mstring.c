#include "ls_header.h"

/**
 * _mstrcmp - modified _strcmp for ls
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: < 0 if s1 < s2, > 0 if s2 > s1, 0 if strings match
 */
int _mstrcmp(const char *s1, const char *s2)
{
	int i = 0;
	int j = 0;

	char a = '\0';
	char b = '\0';

	for ( ; s1[i] != '\0';)
	{
		a = _charup(s1[i]);
		b = _charup(s2[j]);

		if (s1[i] == s2[j]) /* if chars are the same */
		{
			i++;
			j++;
		}
		/* if the letter is the same, ignoring case */
		else if (a == b)
		{
			return (-(s1[i] - s2[j]));
		}
		else
		{
			break;
		}
	}

	return (s1[i] - s2[j]);
}

/**
 * _charup - returns uppercase letter corresponding to a character.
 *
 * @c: the argument character
 *
 * Return: if the character is in [a-z], returns the corresponding upper case
 * character. If the character does not represent a letter in [a-z], returns
 * the input character unchanged.
 */
char _charup(const char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
